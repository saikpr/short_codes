from operator import itemgetter
from math import atan ,pi
import math
import Tkinter
root = Tkinter.Tk()
root.title("Convex Hull Problem!")
root.resizable(0,0)
points = []
stack1=[]
base_point=[]
final=[]
this_point=[]
canvas = Tkinter.Canvas(root, bg="white", width=600, height=600)
canvas.configure(cursor="crosshair")
click=0
point_angles=[]
def point(event):
	global click
	click+=1
	canvas.create_oval(event.x, event.y, event.x+3, event.y+3, fill="black")
	if not [event.x,event.y] in points:
		this_point=[event.x,-1*event.y]
		points.append(this_point)
	
	if click>=3:
		canvas.delete('all')
		for pt in points:
			canvas.create_oval(pt[0], -1*pt[1],pt[0]+3, -1*pt[1]+3, fill="black")
		doit1()


def doit1():
	sorted_points=sorted(points, key=itemgetter(1))  #add  reverse=True
	base_point =sorted_points[0]
	make_polar_list(base_point)
	covexhull(base_point)
	draw_lines(final)

def make_polar_list(a):
	global point_angles
	
	point_angles_positive=[]
	point_angles_negative=[]
	for b in points:
		if b!=a:
			angle=getangle(a,b)
			if angle>=0:
				point_angles_positive.append(b+[angle])
			else:
				point_angles_negative.append(b+[angle])
	point_angles_positive=sorted(point_angles_positive, key=itemgetter(2),reverse=True)
	point_angles_negative=sorted(point_angles_negative, key=itemgetter(2),reverse=True)
	point_angles=point_angles_negative+point_angles_positive
	
def getangle(a,b):
	angle =0
	if (b != a) and( (b[0]-a[0])!=0):
		a1=(b[1]-a[1])
		b1=(b[0]-a[0])
		angle=math.degrees(atan(float(a1)/b1))
		
				
	elif b != a and b[0]-a[0]==0:
		angle=math.degrees(pi/2)
	return angle

def getvectorproduct(a,b,c):
	
	d=((b[0]-a[0])*(c[1]-b[1]))-((b[1]-a[1])*(c[0]-b[0]))
	if d>0:
		return +1
	elif d< 0:
		return -1
	elif d==0:
		print "It happens"
		return 0
def covexhull(base):
	global final
	final.append(base)
	a=point_angles.pop()
	b=point_angles.pop()
	final.append(a)
	final.append(b)
	trigger=True
	while(trigger==True):
		c=final.pop()
		b=final.pop()
		a=final.pop()
		if getvectorproduct(a,b,c)==1:
			final.append(a)
			final.append(b)
			final.append(c)
			try :
				d=point_angles.pop()
				final.append(d)
			except IndexError:
				final.append(base+[0])
				trigger=False

		if getvectorproduct(a,b,c)==-1:
			while getvectorproduct(a,b,c)==-1 :
				b=a
				a=final.pop()
				
			final.append(a)
			final.append(b)
			final.append(c)
			try :
				d=point_angles.pop()
				final.append(d)
			except IndexError:
				final.append(base+[0])
				
	
def draw_lines(fi):
	global base_point
	#fi.append(base_point)
	
	a=fi.pop()
	b=fi.pop()
	global canvas
	canvas.create_line(a[0],-1*a[1],b[0],-1*b[1])
	
	while(fi!=[]):

		canvas.create_line(a[0],-1*a[1],b[0],-1*b[1])
		a=b
		b=fi.pop()	
	canvas.create_line(a[0],-1*a[1],b[0],-1*b[1])



canvas.bind("<Button-1>", point)
canvas.pack()
root.mainloop()