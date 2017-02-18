#include<iostream.h>
#include<conio.h>
#include<ctype.h>
#include<process.h>
struct node{
	    int data;
	    node *link;
	    };
node *push(node *top,int val);
node *pop(node *top,int &val);
void show(node *top);
void main()
{
clrscr();
node *top;
int ch,val;
char opt='y';
top=NULL;
do
 {
 clrscr();
 cout<<"\n\nMain menu";
 cout<<"\n1.Add";
 cout<<"\n2.Delete";
 cout<<"\n3.Traverse";
 cout<<"\n4.Exit";
 cin>>ch;
 switch(ch)
   {
   case 1:do
	  {
	  cout<<"\nEnter the value to be added:";
	  cin>>val;
	  top=push(top,val);
	  cout<<"\nDo you want to add more elements:";
	  cin>>opt;
	  }while(toupper(opt)=='Y');
	  break;
   case 2:do
	  {
	  top=pop(top,val);
	  if(val!=-1)
	  cout<<"\vValue deleted is-->"<<val;
	  cout<<"\nDo you want to delete more elements:";
	  cin>>opt;
	  }while(toupper(opt)=='Y');
	  break;
   case 3:show(top);
	  break;
   case 4:exit(0);
   }
 }while(ch!=4);
getch();
}
node *push(node *top,int val)
  {
  node *temp;
  temp=new node;
  temp->data=val;
  temp->link=NULL;
  if(top==NULL)
    top=temp;
  else
    {
    temp->link=top;
    top=temp;
    }
  return top;
  }
node *pop(node *top,int &val)
  {
  node *temp;
  if(top==NULL)
    {
    cout<<"\nSTACK EMPTY";
    val=-1;
    }
  else
    {
    temp=top;
    top=top->link;
    val=temp->data;
    temp->link=NULL;
    delete temp;
    }
  return top;
  }
void show(node *top)
  {
  node *temp;
  temp=top;
  if(temp==NULL)
    cout<<"\nSTACK EMPTY";
  else
    {
    cout<<"\n\nStack contains:\n\n";
    while(temp!=NULL)
      {
      cout<<"\t"<<temp->data;
      temp=temp->link;
      }
    }
   getch();
  }
