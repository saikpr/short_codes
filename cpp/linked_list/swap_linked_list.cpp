#include <iostream>
using namespace std;

class node{ public:int data;
            node *next;};

int swapfunc(node **head,int n)// n is number of elements in linked list
{
  if (*head==NULL||n==1)
    {cout<<"Linked List Empty or only single element"<<endl;
    return 0;}
  node *prev_lead,*lead,*next_lead,*temp;

  prev_lead=NULL;
  lead=*head;
  next_lead=(*head)->next;

  lead->next=next_lead->next;
  next_lead->next=lead;
  *head=next_lead;
  temp=lead;
  lead=next_lead;
  next_lead=temp;
  while(next_lead->next!=NULL)
    {
      prev_lead=next_lead;
      lead=prev_lead-> next;
      next_lead=lead->next;
      if (lead->next==NULL)
        {cout<<"\nSince The number of nodes is out";
        return 0;}
      lead->next=next_lead->next;
      next_lead->next=lead;
      prev_lead->next=next_lead;
      temp=lead;
      lead=next_lead;
      next_lead=temp;

    }
}


int main(void)
{
    node *head,*temp;
    head=NULL;
    temp=NULL;
    int i=0,num,data;
    cout<<"Enter the number of nodes:";

    cin>>num;
    cout<<endl;
    if (num!=0)
      {head=new node;
      i++;
      cin>>data;
      head->data=data;}
    while(i<num)
      {cin>>data;
       temp=new node;
       temp->data=data;
       temp->next=head;
       head=temp;
       i++;}
    temp=head;
    cout<<"Outputing the Linked list"<<endl;
    while(temp!=NULL)
      {
        cout<<temp->data<<'\t';
        temp=temp->next;
      }
      cout<<endl;
    swapfunc(&head,num);
    temp=head;
    cout<<"Outputing the Linked list"<<endl;
    while(temp!=NULL)
      {
        cout<<temp->data<<'\t';
        temp=temp->next;
      }
      cout<<endl;
}
