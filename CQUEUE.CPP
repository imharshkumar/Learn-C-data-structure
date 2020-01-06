#include<iostream.h>
#include<stdlib.h>
#include<conio.h>

struct node
{
int data;
struct node *next;
};
struct node *front=NULL,*rear=NULL;

void insertion()
{
int a;
cout<<"enter data";
cin>>a;
struct node *temp;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=a;

if(front==NULL&&rear==NULL)
{
temp->next=temp;
front=rear=temp;
}
else
{
rear->next=temp;
temp->next=front;
rear=temp;
}
}


void deletion()
{

if(rear==NULL&&front==NULL)
{
cout<<"empty";
}
else if(rear==front)
{
free(front);
rear=front=NULL;
}
else
{
struct node *t;
t=front;
front=front->next;
rear->next=front;
free(t);
}
}

void display()
{
if(rear==NULL&&front==NULL)
cout<<"empty";
else
{
struct node *t;
t=front;
while(t->next!=front)
{
cout<<t->data;
t=t->next;
}
cout<<t->data;
}
}

void main()
{
clrscr();
int ch=0;

while(ch!=4)
{
cout<<"1. insertion 2. deletion 3. display 4. exit \n emter choice";
cin>>ch;

switch(ch)
{
case 1:
insertion();
break;
case 2:
deletion();
break;
case 3:
display();
break;
case 4:
cout<<"good bye";
}
}
getch();
}




