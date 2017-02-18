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
  node *first,*temp,*last,*first1,*temp1,*last1,*cd;
  int n,h=0,i,k=1,a[100];
  clrscr();
  cout<<"\nEnter how many nodes to be create in the linked list:";
  cin>>n;
  first=new node;
  cout<<"\nEnter the data value of node 1->";
  cin>>first->data;
  first->link=NULL;
  temp=first;
  temp1=temp;
  for(i=1;i<n;i++)
  {
     last= new node;
     last1=new node;
     cout<<"\nEnter the data value of node "<<i+1<<"->";
     cin>>last-> data;
     last->link=NULL;
     last1=last;
     temp->link=last;
     temp1->link=last1;
     temp=last;
     temp1=temp;
  }
  temp=first;
  temp1=temp;
  cout<<"\n\nThe linked list values are:\n";
  while(temp!=NULL)
 {
  if(k<n)
  cout<<temp->data<<"->";
  else
  cout<<temp->data;
  temp=temp->link;
  ++k;
 }
 cout<<"\n\nPress any key to continue";
 getch();
  temp=first;
  k=0;
  while(temp!=NULL)
  {
   if(temp->data%2==0)
   {
    temp1->data=temp->data;
    if(h==0)
    {
     cd=temp1;
     ++h;
    }
    temp1=temp1->link;
   }
   else
   {
    a[k]=temp->data;
    ++k;
   }
   temp=temp->link;
  }
  temp=first;
  k=0;
  while(temp1!=NULL)
  {
   temp1->data=a[k];
   ++k;
   temp1=temp1->link;
  }
  temp=first;
  temp1=cd;
  clrscr();
  cout<<"\n\nThe linked list values after modification:\n";
  k=1;
  while(temp1!=NULL)
 {
  if(k<n)
  cout<<temp1->data<<"->";
  else
  cout<<temp1->data;
  temp1=temp1->link;
  ++k;
 }
  getch();
}

