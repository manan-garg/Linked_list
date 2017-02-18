#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
struct node
{
  char name[50];
  node *link;
};
void main()
{
  node *first[100],*temp,*last,*back;
  int n,i,count=1,h,flag[100];
  for(int m=1;m<=100;++m)
   flag[m]=0;
  do
  {
   clrscr();
   cout<<"\n\t\tMENU";
   cout<<"\n1.add a new person in list";
   cout<<"\n2.delete a person in list";
   cout<<"\n3.add a friend to existing person(max 10 friends are allowed)";
   cout<<"\n4.delete friend from existing person list";
   cout<<"\n5.display all friends";
   cout<<"\n0.exit";
   cout<<"\n\nEnter your choice=";
   cin>>n;
   switch(n)
   {
    case 1:first[count]=new node;
	   cout<<"\n\nEnter the name of the Person no: "<<count<<":";
	   gets(first[count]->name);
	   first[count]->link=NULL;
	   ++count;
	   cout<<"\nPerson Successfully Added";
	   getch();
	   break;
    case 2:if(count==1)
	    cout<<"\nNo person available";
	   else
	   {
	    --count;
	    cout<<"\nLast Person deleted";
	   }
	   getch();
	   break;
    case 3:if(count>1)
	   {
	    cout<<"\nEnter a person no:";
	    cin>>h;
	    if(flag[h]<10)
	    {
	     temp=first[h];
	     while(temp->link!=NULL)
	     {
	      temp=temp->link;
	     }
	     last=new node;
	     cout<<"\nEnter the name of the friend:";
	     gets(last->name);
	     last->link=NULL;
	     temp->link=last;
	     cout<<"\nFriend Successfully added";
	     ++flag[h];
	    }
	    else
	     cout<<"\nOut of limit";
	   }
	   else
	   cout<<"\nWrong Input";
	   getch();
	   break;
    case 4:cout<<"\nEnter a person no:";
	   cin>>h;
	   if(h<count)
	   {
	    temp=first[h];
	    clrscr();
	    while(temp->link!=NULL)
	    {
	     back=temp;
	     temp=temp->link;
	    }
	    back->link=NULL;
	    delete(temp);
	    cout<<"\nLast Friend deleted";
	    --flag[h];
	   }
	   else
	    cout<<"\nWrong Input";
	   getch();
	   break;
    case 5:cout<<"\nEnter a person no:";
	   cin>>h;
	   if(h<count)
	   {
	    temp=first[h];
	    clrscr();
	    cout<<"\nThe linked list values of person no: "<<h<<" are:\n";
	    while(temp->link!=NULL)
	    {
	     cout<<temp->name<<"->";
	     temp=temp->link;
	    }
	    cout<<temp->name;
	   }
	   else
	   cout<<"\nWrong Input";
	   getch();
	   break;
    case 0:break;
    default:cout<<"\nWrong choice";
	    getch();
	    break;
   }
  }while(n!=0);
 getch();
}

