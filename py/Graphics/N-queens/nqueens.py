import Tkinter
n=int(raw_input("Enter The Value of N:"))
a=[[0 for x in xrange(n)] for y in xrange(n)]
b=[[0 for x in xrange(n)] for y in xrange(n)]
c=[[0 for x in xrange(n)] for y in xrange(n)]
def make_move(row):
	global a,b,c,n
	if(row==n):
		print a
		root = Tkinter.Tk()
		qw = Tkinter.PhotoImage(file="qw.gif")
		qb = Tkinter.PhotoImage(file="qb.gif")
		root.title("Prims")
		canvas = Tkinter.Canvas(root, width=64*n, height=64*n)
		for i in xrange(n):
			for j in xrange(n):
				if (i+j)%2==0 :
					canvas.create_rectangle(i*64, j*64, (i+1)*64, (j+1)*64, outline="black", fill="black")
				if (i+j)%2==1:
					canvas.create_rectangle(i*64, j*64, (i+1)*64, (j+1)*64, outline="white", fill="white")
				if a[i][j]==1 and (i+j)%2==1:
					canvas.create_image(i*64+32, j*64+32, image=qb)
				if a[i][j]==1 and (i+j)%2==0:
					canvas.create_image(i*64+32, j*64+32, image=qw)


		canvas.pack()
		root.mainloop()
		exit()
	for j in xrange(n):
		
		if c[row][j]==0 and b[row][j]==0:
		
			a[row][j]=1
			b[row][j]=1
			show_available()
			make_move(row+1)
		
		elif (j==n-1):
		
			back_move(row)
def back_move(row):
	global a,b,c,n
	if (row==0):
		for i in xrange(n):
			if (a[row][i]==1 and i<n):
		

				a[row][i]=0
				b[row][i]=1
				a[row][i+1]=1
				show_available()
				make_move(0)
	for i in xrange(n):
	
		b[row][i]=0
	for i in xrange(n):
	
		if(a[row-1][i]==1):
		
			a[row-1][i]=0
			b[row-1][i]=1
			show_available()
			make_move(row-1)
def show_available():
	global a,b,c,n
	for i in xrange(n):
		for j in xrange(n):
				
				c[i][j]=0
			
	
	for i in xrange(n):
	
		for j in xrange(n): 
		
			if(a[i][j]==1):
			
				for k in xrange(n):
				
					c[i][k]=1
					c[k][j]=1
					
					if(i-k>=0 and (j+k) < n):
						c[i-k][j+k]=1
					if(i+k<n and j-k>=0):
						c[i+k][j-k]=1
					if (i-k>=0 and j-k>=0):
						c[i-k][j-k]=1
					if(i+k<n and j+k<n):
						c[i+k][j+k]=1


make_move(0)
	
		
		

	

		
	




