#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  node *link;
};
//function for deleting element in linked list.
node *delfirst(node *first,int &value);
node *delbetween(node *first,int &value,int val);
node *dellast(node *first,int &value);
void traverse(node *first);
//main programming logic
void main()
{
  clrscr();
  node *first, *temp, *last;
  int i,n,value,choice,val;
  cout<<"\n\n Enter how many nodes in  the linked list:";
  cin>>n;
  //creation of linked list
  first=new node;
  cout<<"\n\n Enter the data value of node 1:";
  cin>>first->data;
  first->link=NULL;
  temp=first;
  for(i=1;i<n;i++)
  {
    last=new node;
    cout<<"\n\n Enter the data value of node "<<i+1<<":";
    cin>>last->data;
    last->link=NULL;
    temp->link=last;
    temp=last;
    temp=last;
  }
  do
  { 
    cout<<"\n\t main menu:";
    cout<<"\n\t 1. For deleting at first";
    cout<<"\n\t 2.For deleting in between";
    cout<<"\n\t 3.For deleting at last";
    cout<<"\n\t 4.Traversing the list";
    cout<<"\n\t 5.For exit";
    cout<<"\n\t Enter your choice:";
    cin>>choice;
    switch(choice)
    {
      case 1:first=delfirst(first,value);
	    if(value!=-1)
	    cout<<"\n\t The deleted data is:"<<value;
	    cout<<"\n\t";
	    break;

      case 2:cout<<"\n\t Enter the value of node which is to be deleted:";
	    cin>>val;
	    first=delbetween(first,value,val);
	    if(value!=-1)
	    cout<<"\n\t The deleted value is:"<<value<<"\n\t";
	    break;

      case 3:first=dellast(first,value);
	    if(value!=-1)
	    cout<<"\n\tThe deleted value is:"<<value<<"\n\t";
	    break;

      case 4:traverse(first);
	     break;

      case 5:exit(0);
    }
  }while(choice!=5);
getch();
}
void traverse(node*first)
{
node *temp;
temp=first;
cout<<"\n the linked listed values are";
while(temp!=NULL)
 {
  cout<<"\n"<<temp->data;
  temp=temp->link;
 }
}

node*delfirst(node*first,int&value)
{
node *temp;
temp=first;
if(first==NULL)
 {
 cout<<"\n list empty";
 value=-1;
 }
else
 {
 value=temp->data;
 first=first->link;
 temp->link=NULL;
 delete(temp);
 }
return(first);
}
node*delbetween(node*first,int &value,int val)
{
 node *temp,*temp1,*back;
 temp=first;
 back=temp;
 temp=first->link;
 if(first==NULL)
 {
 cout<<"\nlist empty";
 value=-1;
 }
 else
 {
 while(temp!=NULL)
 {
 if(temp1->data==val)
 {
  back->link=temp->link;
  temp->link=NULL;
  value=temp->data;
  delete(temp);
  break;
  }
  back=temp;
  temp=temp->link;
  }
  }
  return(first);
  }
  node*dellast(node*first,int &value)
  {
  node *temp;
  node *temp1,*back;
  temp=first;
  if(first==NULL)
  {
  cout<<"\n\tlist empty";
  value=-1;
  }else
  {
  while(temp->link!=NULL)
  {
  back=temp;
  temp=temp->link;
  }
  back->link=NULL;
  value=temp->data;
  delete(temp);
  }
  return(first);
} 
