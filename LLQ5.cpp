#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
# define max 100
int stack[max];
int top;
void push(int stack[],int val,int &top);
int pop(int stack[],int &top);
void show_stack(int stack[],int top);
void main()
{
 int choice,val;
 char opt='y';
 top=-1;
 clrscr();
 do
 {
  clrscr();
  cout<<"\n main menu"
    <<"\n1 Addition"
    <<"\n2 Deletion"
    <<"\n3 traverse"
    <<"\n4 exit";
  cout<<"\n enter your choice:";
  cin>>choice;
  switch(choice)
  {
   case 1:
   do
   {
          cout<<"\n enter the value to be added: ";
    cin>>val;
    push(stack,val,top);
    cout<<"do u want more element(y/n)";
    cin>>opt;
   }
    while(toupper(opt)=='y');
    break;
   case 2:
    opt='y';
    do
     {
      val=pop(stack,top);
      if(val!=-1)
      {
       cout<<"value deleted from the stack"<<val;
       cout<<"\ndo u want more element(y/n)";
       cin>>opt;
      }
     }
      while(toupper(opt)=='y');
      break;
   case 3:
   show_stack(stack,top);
   break;
   case 4:
   exit(0);
  }
 }
  while(choice!=4);
 getch();
}
  void push (int stack[],int val,int&top)
  {
   if(top==max-1)
   {
    cout<<"\n\tstack full";
   }
   else
   {
    top=top+1;
    stack[top]=val;
   }
  }
  int pop (int stack[],int&top)
  {
  int value;
  if(top<0)
  {
  cout<<"\n\tstack empty";
  value=-1;
  }
  else
  {
  value=stack[top];
  top=top-1;
  }
  return(value);
 }
 void show_stack(int stack[],int top)
 {
  int i;
  if(top<0)
  {
   cout<<"\n\tstack empty";
   return;
  }
  i=top;
  clrscr();
  cout<<"\n\tthe value are-->";
  do
   {
    cout<<"\n\t"<<stack[i];
    i=i-1;
   }
    while(i>=0);
    getch();
}

