#include <iostream>
#include <pthread.h>
#define MAX 5
#define MAXW 10
using namespace std;
int que[MAX];
int front,end_val,len;
pthread_cond_t cond;
pthread_mutex_t mut;

void *producer (void *data);
void *consumer (void *data);

int main ()
{	front=0;
	end_val=0;
	len=0;
	pthread_t t1,t2;
	int it1,it2,*data;
	pthread_mutex_init(&mut,NULL);
	pthread_cond_init(&cond,NULL);
	it1= pthread_create(&t1,NULL,producer,(void *)data);
	it1= pthread_create(&t2,NULL,consumer,(void *)data);
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	return 0;

}

void *producer (void *data)
{
	int i=-1;

	while(i++<MAXW)
	{

		pthread_mutex_lock(&mut);
		if (len==MAX)
		{

			cout<<"Producer Start Waiting\n";
			pthread_cond_wait(&cond,&mut);

		}
		que[end_val]=i;
		cout<<"Produced :"<<i<<endl;
		end_val = (end_val +1 )%MAX;
		len++;
		pthread_mutex_unlock(&mut);

		if (len==1)
		{

			cout<<"Consumer Signalled\n";
			pthread_cond_signal(&cond);
		}

	}
}


void *consumer (void *data)
{
	int consumed=0;

	while(consumed<MAXW)
	{

		pthread_mutex_lock(&mut);
		if(len==0)
		{
			cout<<"Consumer Waiting \n";
			pthread_cond_wait(&cond,&mut);

		}
		cout<<"Consumed :"<<que[front]<<endl;
		consumed=que[front];
		front =(front + 1) % MAX;
		len --;
		pthread_mutex_unlock(&mut);
		if (len == MAX-1)
		{	cout<<len;
			cout<<"Producer Signalled\n";
			pthread_cond_signal(&cond);
		}

	}
}