#include<iostream.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<ctype.h>
# define max 100
int queue[max];
int top,front,rear;
void add_q(int queue[],int val,int &rear);
int del_q(int queue[],int &front,int rear);
void show_q(int queue[],int front,int rear);
void main()
{
 int choice,val;
 char opt='y';
 rear=-1;
 front=-1;
 top=-1;
 clrscr();
 do
  {
   clrscr();
   cout<<"\n main menu"
       <<"\n1. addition"
       <<"\n2. deletion"
       <<"\n3. traverse"
       <<"\n4. exit";
   cout<<"\n enter your choice from above:";
   cin>>choice;
   switch(choice)
   {
    case 1:
    do
    {
     cout<<"\n enter the value to be added :";
     cin>>val;
     add_q(queue,val,rear);
     cout<<"do u want more element(y/n):";
     cin>>opt;
    }
     while(toupper(opt)=='y');
     break;
    case 2:
    opt='y';
   do
   {
    val=del_q(queue,front,rear);
    if(val!=-1)
    cout<<"\nvalue deleted from the queue:"<<val;
    cout<<"\ndo u want more element(y/n):";
    cin>>opt;
   }
    while(toupper(opt)=='y');
    break;
    case 3:
    show_q(queue,front,rear);
    break;
    case 4:
    exit(0);
  }
 }
while(choice!=4);
getch();
}

void add_q(int queue[],int val,int &rear)
{
 if(rear==max)
cout<<"\n \t Queue full!!!!";
 else
 {
  rear=rear+1;
  queue[rear]=val;
 }
}

int del_q(int queue[],int &front,int rear)
{
  int value;
  if(front==rear)
  {
    cout<<"\n \t Queue empty!!!!";
    value=-1;
  }
  else
  {
    front=front+1;
    value=queue[front];
  }
  return(value);
}

void show_q(int queue[],int front,int rear)
{
  clrscr();
  if(front==rear)
  {
    cout<<"\n \t Queue empty!!!";
    return;
  }
  else
  {
    cout<<"\nThe values are:";
    do
    {
      front=front+1;
      cout<<"\n"<<queue[front];
    }
    while(front!=rear);
  getch();
  }
}
