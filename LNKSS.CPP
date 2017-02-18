#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  node *link;
};
node *swap(node *first,int a,int b);
node *shift(node *last,node *first,char ch,int j,int n);
void display(node *first,int n);
void main()
{
 node *first,*temp,*last;
 int n,i,a,b,c,j;
 char ch;
 clrscr();
 cout<<"\nEnter how many nodes to be create in the linked list:";
 cin>>n;
 first=new node;
 cout<<"\nEnter the data value of node 1->";
 cin>>first->data;
 first->link=NULL;
 temp=first;
 for(i=1;i<n;i++)
 {
  last= new node;
  cout<<"\nEnter the data value of node "<<i+1<<"->";
  cin>>last-> data;
  last->link=NULL;
  temp->link=last;
  temp=last;
 }
 temp=first;
 clrscr();
 do
 {
  clrscr();
  cout<<"\n\t\tMENU";
  cout<<"\n1.Swap";
  cout<<"\n2.Shift";
  cout<<"\n3.Traverse";
  cout<<"\n0.Exit";
  cout<<"\nEnter you choice=";
  cin>>c;
  switch(c)
  {
   case 1:cout<<"\nEnter the two node positions which you want to swap(a<b)=";
	  cin>>a>>b;
	  if(a<=n&&b<=n&&a<b)
	  {
	   first=swap(first,a,b);
	  }
	  else
	  {
	   cout<<"\nWrong Input";
	   getch();
	  }
	  break;
   case 2:cout<<"\nEnter character(+/-):";
	  cin>>ch;
	  cout<<"\nEnter number to shift by:";
 	  cin>>j;
  	  if(j<n&&(ch=='+'||ch=='-'))
  	  first=shift(last,first,ch,j,n);
  	  else
	  { 
	   cout<<"\nWrong Input";
  	   getch();
  	  }
  	  break;
   case 3:display(first,n);
  	  getch();
  	  break;
   case 0:break;
   default:cout<<"\nWrong Input";
  	   getch();
       	   break;
  }
 }while(c!=0);
  getch();
}
void display(node *first,int n)
{
 int i=1;
 node *temp;
 temp=first;
 cout<<"\nThe linked list values are:\n";
 while(temp!=NULL)
 { 
  if(i<n)
  cout<<temp->data<<"->";
  else
  cout<<temp->data;
  temp=temp->link;
  ++i;
 }
}
node *swap(node *first,int a,int b)
{
 node *temp,*fix1,*fix2,*before1,*before2,*temp2;
 temp=new node;
 temp=first;
 fix1=new node;
 fix2=new node;
 temp2=new node;
 before1=new node;
 before2=new node;
 for(int i=1;temp!=NULL;++i)
 {
  if(i==a)
  {
   fix1=temp;
   break;
  }
  before1=temp;
  temp=temp->link;
 }
 temp=first;
 for(i=1;temp!=NULL;++i)
 {
  if(i==b)
  {
   fix2=temp;
   break;
  }
  before2=temp;
  temp=temp->link;
 }
 temp=first;
 if(a==1&&a+1==b)
 {
  fix1->link=fix2->link;
  fix2->link=fix1;
  temp=fix2;
 }
 else
 if(a==1&&a+1!=b)
 {
  temp2->link=fix2->link;
  fix2->link=fix1->link;
  before2->link=fix1;
  temp=fix2;
  fix1->link=temp2->link;
 }
 else
 if(a+1==b)
 {
  before1->link=fix2;
  fix1->link=fix2->link;
  fix2->link=fix1;
 }
 else
 {
  temp2->link=fix2->link;
  before1->link=fix2;
  fix2->link=fix1->link;
  before2->link=fix1;
  fix1->link=temp2->link;
 }
 return temp;
}
node *shift(node *last,node *first,char ch,int j,int n)
{
 node *temp,*temp1;
 temp=new node;
 temp=first;
 temp1=new node;
 if(ch=='+')
 {
  last->link=temp;
  for(int i=1;i<=n;++i)
  {
   if(i==(n-j+1))
   temp1=temp;
   temp=temp->link;
  }
  temp=first;
  for(i=1;i<=n;++i)
  {
   if(i==n-j)
   {
    temp->link=NULL;
    break;
   }
   temp=temp->link;
  }
  temp=temp1;
 }
 else
 if(ch=='-')
 {
  last->link=temp;
  for(int i=1;i<=n;++i)
  {
   if(i==(j+1))
   temp1=temp;
   temp=temp->link;
  }
  temp=first;
  for(i=1;i<=n;++i)
  {
   if(i==j)
   {
    temp->link=NULL;
    break;
   }
   temp=temp->link;
  }
  temp=temp1;
 }
 return temp;
}


