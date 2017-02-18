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
  node *first,*temp,*last,*first1,*temp1,*last1,*first2,*temp2,*last2;
  int r[10][10],t[10][10],w[10][10],k1,c=0,f=1,c1=0,f1=1,n,i,a,b,count=0,count1=0,k,l,g,q,v=0,n1,count2=0,count3=0,o,p;
  clrscr();
  cout<<"\nEnter how many rows to be create in the sparse matrix I:";
  cin>>a;
  cout<<"\nEnter how many columns to be created in the sparse matrix I:";
  cin>>b;
  n=a*b;
  if(a!=0&&b!=0)
{ cout<<"\nEnter the data in n nodes:\n";
  first=new node;
  cout<<"\nEnter the data value of node 1->";
  cin>>first->data;
  t[0][0]=first->data;
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
     if(i%b==0)
     {
      ++c;
      f=0;
      t[c][f]=last->data;
      ++f;
     }
     else
     {
      t[c][f]=last->data;
      ++f;
     }
     if(last->data==0)
     ++count;
     else
     ++count1;
     last->link=NULL;
     temp->link=last;
     temp=last;
  }
  if(count1>=count)
  {
   cout<<"\nWrong Input as No: of zeroes are less than number entries";
   goto label;
  }
  else
 {
  temp=first;
  clrscr();
  cout<<"The sparse matrix I is:\n\n";
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
 }
 }
 else
 cout<<"\nWrong Input";
  getch();
  clrscr();
  cout<<"\nEnter how many rows to be create in the sparse matrix II:";
  cin>>o;
  cout<<"\nEnter how many columns to be created in the sparse matrix II:";
  cin>>p;
  n1=o*p;
  if(o!=0&&p!=0)
{ cout<<"\nEnter the data in n nodes:\n";
  first1=new node;
  cout<<"\nEnter the data value of node 1->";
  cin>>first1->data;
  w[0][0]=first1->data;
  first1->link=NULL;
  temp1=first1;
  if(temp1->data==0)
  ++count2;
  else
  ++count3;
  for(i=1;i<n1;i++)
  {
     last1=new node;
     cout<<"\nEnter the data value of node "<<i+1<<"->";
     cin>>last1->data;
     if(i%p==0)
     {
      ++c1;
      f1=0;
      w[c1][f1]=last1->data;
      ++f1;
     }
     else
     {
      w[c1][f1]=last1->data;
      ++f1;
     }
     if(last1->data==0)
     ++count2;
     else
     ++count3;
     last1->link=NULL;
     temp1->link=last1;
     temp1=last1;
  }
  if(count3>=count2)
  {
   cout<<"\nWrong Input as No: of zeroes are less than number entries";
   goto label;
  }
  else
 {
  temp1=first1;
  clrscr();
  cout<<"The sparse matrix II is:\n\n";
  v=0;
  while(temp1!=NULL)
  { if(v==p)
    {
     v=0;
     cout<<"\n";
    }
    cout<<temp1->data<<"\t";
    ++v;
    temp1=temp1->link;
  }
  temp1=first1;
 }
 }
 else
 cout<<"\nWrong Input";
  getch();
  clrscr();
  if(b==o)
  { k1=1;
   for(i=0;i<=c;++i)
   {
    for(int j=0;j<f1;++j)
    {
     r[i][j]=0;
     for(int u=0;u<f;++u)
      r[i][j]=r[i][j]+(t[i][u]*w[i][u]);
     if(i==0&&j==0)
     {
      first2=new node;
      first2->data=r[i][j];
      first2->link=NULL;
      temp2=first2;
     }
     else
     {
      last2=new node;
      last2->data=r[i][j];
      last2->link=NULL;
      temp2->link=last2;
      temp2=last2;
     }
    }
   }
  }
  else
  k1=0;
  if(k1==1)
  {
   temp2=first2;
  clrscr();
  cout<<"The product matrix is:\n\n";
  v=0;
  while(temp2!=NULL)
  { if(v==f1)
    {
     v=0;
     cout<<"\n";
    }
    cout<<temp2->data<<"\t";
    ++v;
    temp2=temp2->link;
  }
 }
 else
  cout<<"\nSorry!!! Matrix multiplication can't be done";
  label:
  int l1;
  getch();
 }


