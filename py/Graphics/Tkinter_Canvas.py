from operator import itemgetter
from math import tan ,pi
import Tkinter
root = Tkinter.Tk()
root.title("Simple Graph")
root.resizable(0,0)
points = []
spline = 0
sorted_points=[]
base_point=[]
this_point=[]
c = Tkinter.Canvas(root, bg="white", width=300, height= 300)
c.configure(cursor="crosshair")
point_angles=[]
def point(event):
	c.create_oval(event.x, event.y, event.x+1, event.y+1, fill="black")
	if not [event.x,event.y] in points:
		this_point=[event.x,-1*event.y]
		points.append(this_point)
def doit(event):
	sorted_points=sorted(points, key=itemgetter(1),reverse=True)  #add  reverse=True
	base_point =sorted_points[0]
	polarangle(base_point)
	print base_point
def polarangle(a):
	global point_angles
	print a
	point_angles=[]
	for b in points:
		if (b != a) and( (b[0]-a[0])!=0):
			angle=tan((b[1]-a[1])/(b[0]-a[0]))
			c.create_line(a,b)
			point_angles.append(b+[angle])
			print angle
		elif b != a and b[0]-a[0]==0:
			angle=pi/2
			c.create_line(a[0],-1*a[1],b[0],-1*b[1])
			point_angles.append(b+[angle])
			print angle
	point_angles=sorted(point_angles, key=itemgetter(2))

c.bind("<Button-1>", point)
c.bind("<Button-3>", doit)
c.pack()
root.mainloop()