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
  int n,i,a,b,count=0,count1=0,o=0,k,l,g,q,v=0;
  clrscr();
  cout<<"\nEnter how many rows to be create in the sparse matrix:";
  cin>>a;
  cout<<"\nEnter how many columns to be created in the sparse matrix:";
  cin>>b;
  n=a*b;
  if(a!=0&&b!=0)
{ cout<<"\nEnter the data in n nodes:\n";
  first=new node;
  cout<<"\nEnter the data value of node 1->";
  cin>>first->data;
  first->link=NULL;
  temp=first;
  if(temp->data==0)
  ++count;
  else
  ++count1;
  for(i=1;i<n;i++)
  {
     last= new node;
     cout<<"\nEnter the data value of node "<<i+1<<"->";
     cin>>last-> data;
     if(last->data==0)
     ++count;
     else
     ++count1;
     last->link=NULL;
     temp->link=last;
     temp=last;
  }
  if(count1>=count)
  cout<<"\nWrong Input as No: of zeroes are less than number entries";
  else
 {
  temp=first;
  clrscr();
  cout<<"The sparse matrix is:\n\n";
  while(temp!=NULL)
  { if(v==b)
    {
     v=0;
     cout<<"\n";
    }
    cout<<temp->data<<"\t";
    ++v;
    temp=temp->link;
  }
  temp=first;
  cout<<"\n\nEnter the row number to locate the element=";
  cin>>k;
  cout<<"\nEnter the column number to locate the element=";
  cin>>l;
  if(k>a||l>b)
  cout<<"\nWrong Input";
  else
  {
  g=((k-1)*b)+l;
  for(i=1;i<=n;++i)
  {
   if(i==g)
   {
    ++o;
    q=temp->data;
    break;
   }
   temp=temp->link;
  }
  if(o!=0)
  cout<<"\nRequired element="<<q;
  else
  cout<<"\nElement not found";
 }}
}
else
cout<<"\nWrong Input";
  getch();
}

