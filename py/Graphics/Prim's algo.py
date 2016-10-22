import Tkinter
from Queue import PriorityQueue as pri 
from math import sin,cos,pi
n=int(raw_input("Enter The Value Of n:"))



adj=[[0 for x in xrange(n)] for y in xrange(n)]
v1=[False for x in xrange(n)]#visitedn
for i in xrange(n):
	adj[i]=raw_input().split()
for i in xrange(n):
	for j in xrange(n):
		adj[i][j]=int(adj[i][j])
adj2=[[0 for x in xrange(n)] for y in xrange(n)]
#get the adj list and n
v1[0]=True
def prims():
	global v1,adj,adj2
	while True:
		myq=pri()
		print ""
		print v1
		for j in xrange(n):
			if v1[j]== True:
				for i in xrange(n):
					if adj[j][i] != 0 :
						temp=[adj[j][i]]
						temp.append([j,i])
						print temp
						myq.put(temp)
					
		
		while myq.empty()==False:
			thy=myq.get()
			edg=thy.pop()
			edgt=edg
			fvert=edgt.pop()
			if v1[fvert]==False:
				v1[fvert]=True
				j=fvert
				i=edg.pop()
				adj2[i][j]=thy.pop()
				adj2[j][i]=adj2[i][j]
				break
		if v1==[True for x in xrange(n)]:
			break
prims()
print adj2
print v1
root = Tkinter.Tk()
root.title("Prims")
canvas = Tkinter.Canvas(root, bg="white", width=500, height=500)
for i in xrange(n):
	x= round(sin((2*i*pi)/n),5)
	y= round(cos((2*i*pi)/n),5)
	canvas.create_oval(249+100*x, 249+100*y, 251+100*x,251+100*y, fill="black")
	canvas.create_text(270+100*x,249+100*y, text =str(i))
for i in xrange(n):
	for j in xrange(i,n):
		if adj2[i][j]!=0:

			x1= 250+100*round(sin((2*i*pi)/n),5)
			y1= 250+100*round(cos((2*i*pi)/n),5)
			x2= 250+100*round(sin((2*j*pi)/n),5)
			y2= 250+100*round(cos((2*j*pi)/n),5)
			canvas.create_line(x1,y1,x2,y2)
			canvas.create_text((x1+x2)/2+10,(y1+y2)/2, text =str(adj2[i][j]))

canvas.pack()
root.mainloop()	