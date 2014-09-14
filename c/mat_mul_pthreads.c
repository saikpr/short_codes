/**
    Matrix Multiplication Using Pthreads on Unix
    mat_mul_pthreads.c
    Purpose: Multiplies two Matrix to obtain a New Matrix

    @author Sainyam Kapoor
    @version 0.1 15/09/2014
*/
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
//int a[100][100]={{1,2,3},{4,5,6},{7,8,9}},b[100][100]={{1,2,3},{4,5,6},{7,8,9}},c[100][100],n;
typedef struct coor {int x_st,y_st,x_ed,y_ed;}  xycood;
int a[100][100],b[100][100],c[100][100],n;
void *multimat(void *xytemp);

int main()
{
	pthread_t tn[10000];  // max supported threads 10000
	xycood xyvar[10000];
	int threadcount,i,j,it[10000];
	float gpvar;
	printf("Enter the Number of threads :");
	scanf("%d",&threadcount);
	printf("\nEnter the Size N:");
	scanf("%d",&n);
	gpvar=(n*n)/(float)threadcount;
	printf("\nEnter the First Matrix");
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			scanf("%d",&a[i][j]);
			c[i][j]=0;
		}
	printf("\nEnter the Second Matrix");
	for (i=0;i<n;i++)
		for (j=0;j<n;j++)
		{
			scanf("%d",&b[i][j]);
		}
	
	

	xyvar[i].x_st=0;
	xyvar[i].y_st=0;
	xyvar[i].x_ed=(gpvar- 1)/n;
	xyvar[i].y_ed=(((int)gpvar-1)%n);
	//printf("%f \n",gpvar);
	for(i=1;i<threadcount;i++)
		{ 
			xyvar[i].x_st=xyvar[i-1].x_ed + (xyvar[i-1].y_ed+1)/n -(xyvar[i-1].y_ed)/n;
			
			xyvar[i].y_st=(xyvar[i-1].y_ed+1)%n;
			
			xyvar[i].y_ed= (int)((i+1)*gpvar-1)%n;

			xyvar[i].x_ed= (int)((i+1)*gpvar-1)/n;
		}
	/*
	for(i=0;i<threadcount;i++)
		{ 

			printf("%d %d %d %d %d\n",xyvar[i].x_st,xyvar[i].y_st,xyvar[i].x_ed,xyvar[i].y_ed,((xyvar[i].x_ed-xyvar[i].x_st )*n+(xyvar[i].y_ed-xyvar[i].y_st)+1));
		}
	*/
	for (i=0;i<threadcount;i++)
		{
			it[i]= pthread_create(&tn[i],NULL,multimat,(void *)(xyvar+i));
		}
	for (i=0;i<threadcount;i++)
		{
			pthread_join(tn[i],NULL);
		}

	for (i=0;i<n;i++)
		{	
			for (j=0;j<n;j++)
			{
				printf("%d ",c[i][j]);
			}
			printf("\n");
		}

	return(0);
}
void *multimat(void *xyt)
{
	xycood *xytemp;
	xytemp=(xycood *)xyt;
	int i=xytemp->x_st ,j=xytemp->y_st ,l,jp,k,varlen;
	varlen=((xytemp->x_ed-xytemp->x_st )*n+(xytemp->y_ed-xytemp->y_st)+1);
	//printf("ts%d %d %d\n",i,j,varlen);
	for(l=0;l<varlen;l++)
	{	
		for (k=0;k<n;k++)
		{
			c[i][j]+=a[i][k]*b[k][j];
		}
	j+=1;
	if (j==n)
		{
			i++;
			j=0;
		}
	}
}



