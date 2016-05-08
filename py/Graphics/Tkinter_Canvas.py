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
canvas = Tkinter.Canvas(root, bg="white", width=300, height= 300)
canvas.configure(cursor="crosshair")

point_angles=[]
def point(event):
	canvas.create_oval(event.x, event.y, event.x+1, event.y+1, fill="black")
	if not [event.x,event.y] in points:
		this_point=[event.x,-1*event.y]
		points.append(this_point)
def doit(event):
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
		print 1
		return +1
	elif d< 0:
		print -1
		return -1
	elif d==0:
		print 0
		return 0
def covexhull(base):
	
	stack1.append(base)
	
	stack1.append(point_angles.pop())
	stack1.append(point_angles.pop())
	trigger=True
	while(trigger==True):
		c=stack1.pop()
		c=c[0:2]
		b=stack1.pop()
		b=b[0:2]
		a=stack1.pop()
		a=a[0:2]
		final.append(a)
		if getvectorproduct(a,b,c)==1:
			final.append(b)
			stack1.append(b)
			stack1.append(c)
			try :
				stack1.append(point_angles.pop())
			except IndexError:
				stack1.append(base)
				trigger=False
		elif getvectorproduct(a,b,c)==-1:
			stack1.append(a)

			stack1.append(c)
			try :
				stack1.append(point_angles.pop())
			except IndexError:
				stack1.append(base)
				trigger=False
	c=stack1.pop()
	c=c[0:2]
	b=stack1.pop()
	b=b[0:2]
	a=stack1.pop()
	a=a[0:2]
	final.append(b)
	final.append(base)
def covex1(base):
	stack1=[]
	stack1.append(base)
	
	stack1.append(point_angles.pop())
	stack1.append(point_angles.pop())
	trigger=True
	while(trigger==True):
		c=stack1.pop()
		c=c[0:2]
		b=stack1.pop()
		b=b[0:2]
		a=stack1.pop()
		a=a[0:2]
		fim.append(a)
		if getvectorproduct(a,b,c)==1:
			fim.append(b)
			stack1.append(b)
			stack1.append(c)
			try :
				stack1.append(point_angles.pop())
			except IndexError:
				stack1.append(base)
				trigger=False
		elif getvectorproduct(a,b,c)==-1:
			stack1.append(a)
			
			stack1.append(c)
			try :
				stack1.append(point_angles.pop())
			except IndexError:
				stack1.append(base)
				trigger=False
	c=stack1.pop()
	c=c[0:2]
	b=stack1.pop()
	b=b[0:2]
	a=stack1.pop()
	a=a[0:2]
	fim.append(b)
	fim.append(base)
def draw_lines(fi):
	
	print fi
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
canvas.bind("<Button-3>", doit)
canvas.pack()
root.mainloop()