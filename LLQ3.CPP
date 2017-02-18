#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
node *link;
};
node *addfirst(node*first,int value);
node *addbetween(node*first,int value,int val);
node *addlast(node*first,int value);
void traverse(node *first);
void main()
{
 clrscr();
 int i,n, choice,val,value;
 node *first,*temp,*last;
 cout<<"enter how many nodes to created in link list:";
 cin>>n;
 first=new node;
 cout<<"\nenter the element of node 1->";
 cin>>first->data;
 first->link=NULL;
 temp=first;
 for(i=1;i<n;i++)
  {
  last=new node;
  cout<<"\nenter the element of node "<<i+1<<"->";
  cin>>last->data;
  last->link=NULL;
  temp->link=last;
  temp=last;
  }
 do
 {
 cout<<"\nmain menu";
 cout<<"\n1.inserting at first";
 cout<<"\n2.inserting at between";
 cout<<"\n3.insert at last";
 cout<<"\n4.transversing at last";
 cout<<"\n5.exit";
 cout<<"\nenter your choice->";
 cin>>choice;
 switch(choice)
  {
  case 1:cout<<"\nenter data value to inserted->";
	 cin>>value;
	 first=addfirst(first,value);
	 break;
  case 2:cout<<"enter data value to be inserted-->";
	 cin>>value;
	 cout<<"enter the value of node after which insertion is made-->";
	 cin>>val;
	 first=addbetween(first,value,val);
	 break;
  case 3:cout<<"enter the data to be inserted-->";
	 cin>>value;
	 first=addlast(first,value);
	 break;
  case 4:traverse(first);
	 break;
  case 5:exit(0);
  }
 }
 while(choice!=0);
getch();
}
void traverse(node*first)
 {
 node*temp;
 temp=first;
 cout<<"the linked list value are-->";
 while (temp!=NULL)
  {
  cout<<"\n"<<temp->data;
  temp=temp->link;
  }
 }
node*addfirst(node*first,int value)
 {
 node*temp;
 temp=new node;
 temp->data=value;
 temp->link=first;
 first=temp;
 return(first);
 }
node*addbetween(node*first,int value,int val)
 {
 node *temp;
 node *temp1;
 temp=new node;
 temp->data=value;
 temp1=first;
 while(temp1!=NULL)
  {
  if(temp1->data==val)
   {
   temp->link=temp1->link;
   temp1->link=temp;
   break;
   }
  temp1=temp1->link;
  }
  return(first);
 }
node*addlast(node*first,int value)
 {
 node *temp;
 node *temp1,*back;
 temp=new node;
 temp->data=value;
 temp->link=NULL;
 back=first;
 temp1=first->link;
 while(temp1!=NULL)
  {
  back=temp1;
  temp1=temp1->link;
  }
 back->link=temp;
 return(first);
 }

