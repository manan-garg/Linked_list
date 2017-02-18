#include<ctype.h>
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<stdio.h>
struct node
{
  int data;
  node*link;
};
node*add_q(node*rear,int val);
node*del_q(node*front,int &val);
void show_q(node*front);
void main()
{
 clrscr();
 node *rear,*front;
 int choice,val;
 char opt='y';
 front=rear=NULL;
 do
 {
  clrscr ();
  cout<<"\nmain menu";
  cout<<"\n1.addition of queue";
  cout<<"\n2.deletion from queue";
  cout<<"\n3.traverse of queue";
  cout<<"\n4.exit from menu";
  cout<<"\nenter your choice from above:";
  cin>>choice;
  switch(choice)
  {
    case 1:
    do
     {
      cout<<"\nenter data value to be added in the queue->";
      cin>>val;
      rear=add_q(rear,val);
      if(front==NULL)
      front=rear;
      cout<<"\ndo you want to add more element<y/n>:";
      cin>>opt;
      }
       while(toupper(opt)=='y');
       break;
     case 2:
     opt='y';
     do
     {
      front=del_q(front,val);
      if(front==NULL)
      rear=front;
      if(val!=-1)
      cout<<"\nvalue deleted from queue is->"<<val;
      cout<<"\ndo you want to delete more element:";
      cin>>opt;
     }
      while(toupper(opt)=='y');
      break;
     case 3:
     show_q(front);
     case 4:
     exit(0);
    }
 }
  while(choice!=4);
getch();
}
node *add_q(node*rear,int val)
{
 node*temp;
 temp=new node;
 temp->data=val;
 temp->link=NULL;
 if(rear==NULL)
 rear=temp;
 else
 {
  rear->link=temp;
  rear=temp;
 }
 return(rear);
}
node *del_q(node *front,int &val)
{
 node *temp;
 clrscr();
 temp=front;
 front=front->link;
 val=temp->data;
 temp->link=NULL;
 delete temp;
 return (front);
}

void show_q(node *front)
{
  node *temp;
  temp=front;
  clrscr();
  cout<<"\nthe values are:";
 while(temp!=NULL)
 {
  cout<<"\n"<<temp->data;
  temp=temp->link;
 }
getch();
}
