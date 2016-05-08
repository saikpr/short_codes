/*Program to implement BFS algo
Version 1.00 09-01-2014
By swat
*/
import java.util.*;
class queue
{
	int q[]=new int[1001];
	int front=0,rear=1000,n=1000;
	void ins(int a)
	{
		if((front==1 && rear==n) || (front==rear+1))
		{
			System.out.print("Queue is full");
			System.exit(0);
		}
		if(front==0)
		{
			front=1;
			rear=1;
		}
		else if(rear==n)
		{
			rear=1;
		}
		else
			rear=rear+1;
		q[rear]=a;
	}
	void rem()
	{
		if(front==rear)
		{
			front=0;
			rear=0;
		}
		else if(front==n)
		{
			front=1;
		}
		else
			front=front+1;
	}
	boolean empty()
	{
		if(front==0)
			return true;
		else
			return false;
	}
	int front()
	{
		return q[front];
	}
}
public class bfs
{
	public static void main(String aa[])
	{
		Scanner obj=new Scanner(System.in);
		int i,j,n,a;
		System.out.print("Enter the no. of nodes: ");
		n=obj.nextInt();
		System.out.println("Enter the adjacency matrix: ");
		int adj[][]=new int[n+1][n+1];
		int visit[]=new int[n+1];
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
				adj[i][j]=obj.nextInt();
		}
		queue o=new queue();
		o.ins(1);
		visit[1]=1;
		System.out.print("Order of BFS is : ");
		while(!o.empty())
		{
			a=o.front();
			for(i=1;i<=n;i++)
			{
				if(adj[a][i]==1 && visit[i]==0)
				{
					o.ins(i);
					visit[i]=1;
				}
			}
			System.out.print(o.front()+" ");
			o.rem();
		}
	}
}