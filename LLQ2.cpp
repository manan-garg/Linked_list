#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
 int data;
 node *link;
};
void main()
{
 node *first,*temp,*last;
 int n,i,flag,item;
 clrscr();
 cout<<"\n\tEnter how many nodes to be create in the linked list:";
 cin>>n;
 first=new node;
 cout<<"\n\t Enter the data value of node 1->";
 cin>>first->data;
 first->link=NULL;
 temp=first;
 for(i=1;i<n;i++)
 {
  last= new node;
  cout<<"\n\t\  Enter the data value of node "<<i+1<<"->";
  cin>>last-> data;
  last->link=NULL;
  temp->link=last;
  temp=last;
 }
 temp=first;
 clrscr();
 cout<<"The linked list value are:\n";
 while(temp!=NULL)
 {
  cout<<"\n"<<temp->data;
  temp=temp->link;
 }
 flag=0;
 cout<<"\n\ndata value to be searched-->";
 cin>>item;
 temp=first;
 while(temp!=NULL)
 {
  if(temp->data==item)
  {
   flag=1;
   break;
  }
  temp=temp->link;
 }
 if(flag==1)
 cout<<"\n\n\tsearch is successful";
 else
 cout<<"\n\n\tsearch is unsuccessful";
 getch();
}
