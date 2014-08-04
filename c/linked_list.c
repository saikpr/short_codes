#include <stdio.h>

struct node{int data;
struct node *next;};
int main()
{

  typedef struct node anode;
  anode *head, *temp;
  temp=(anode *)malloc(sizeof(anode));
  temp->data=-1;
  temp->next=NULL;
  head=temp;
  int i=0;
  while(i<5)
    {
        temp= (anode *)malloc(sizeof(anode));
        temp->data=i;
        i++;
        temp->next=head;
        head=temp;
    }
  temp=head;
  while (temp!=NULL)
    {
      printf("%d",temp->data);
      temp=temp->next;
    }


}
