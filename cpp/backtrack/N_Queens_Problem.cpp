#include<iostream>
#include<cstdlib>
using namespace std;
int n=8;
int a[100][100],b[100][100],c[100][100];
int make_move(int row);
int show_available()
{for(int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			{	
				c[i][j]=0;
			}
	int i,j,k;
	for (i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j]==1)
			{
				for(k=0;k<n;k++)
				{
					c[i][k]=1;
					c[k][j]=1;
					
					if(i-k>=0&&j+k<n)
					c[i-k][j+k]=1;
					if(i+k<n&&j-k>=0)
					c[i+k][j-k]=1;
					if (i-k>=0&&j-k>=0)
					c[i-k][j-k]=1;
					if(i+k<n&&j+k<n)
					c[i+k][j+k]=1;


				}
			}
		}

	}
}
int back_move(int row)
{	
	int	i=0,j;
	
	
	if (row==0)
	{
		for (i=0;i<n;i++)
		{	if (a[row][i]==1&&i<n)
			{
				a[row][i]=0;
				b[row][i]=1;
				a[row][i+1]=1;
				show_available();
				make_move(0);
			}
			

		}

	}
	for (i=0;i<n;i++)
	{
		b[row][i]=0;

	}
	for(i=0;i<n;i++)
	{
		if(a[row-1][i]==1)
		{
			a[row-1][i]=0;
			b[row-1][i]=1;
			show_available();
			make_move(row-1);

		}
	}




}
int make_move(int row)
{	int i,j=0;
	
	if(row==n)
	{
		for(i=0;i<n;i++)
		{	

			for (j=0;j<n;j++)
			{
				cout<<a[i][j];

			}
			cout<<endl;
		}
		exit(0);
	}
	for (j=0;j<n;j++)
	{	
		if (c[row][j]==0&&b[row][j]==0)
		{
			a[row][j]=1;
			b[row][j]=1;
			show_available();
			make_move(row+1);
		}
		else
		if (j==n-1)
		{
			back_move(row);
		}

	}


}



int main()
{
	//here a is for position of queens, b is for untested position of queens for thatt row
	//and c is for available position of queen
	cout<<"Enter The Value For N :";
	//cin>>n;
	n=8;
	cout<<n<<endl;
	for(int i=0;i<n;i++)
		for (int j=0;j<n;j++)
			{	a[i][j]=0;
				b[i][j]=0;
				c[i][j]=0;
			}
	make_move(0);
	
	
}																																																																																																																																																																																								