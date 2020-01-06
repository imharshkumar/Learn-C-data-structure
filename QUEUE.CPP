#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
int data;
struct node *next;
};
struct node* rear=NULL;
struct node* front=NULL;
void insertion();
void deletion();
void display();
void main()
{
clrscr();
int q;
while(q!=4)
{
cout<<"Enter 1.Insertion, 2.Deletion, 3.Display, 4.Exit";
cin>>q;
switch(q)
{
case 1: insertion();
	cout<<"Insertion occurs";
	break;
case 2: deletion();
	cout<<"Deletion occurs";
	break;
case 3: display();
	break;
case 4: cout<<"press enter for break";
}
}
getch();
}

void insertion()
{
int d;
struct node* temp;
cout<<"Enter value";
cin>>d;

temp= (struct node *)malloc(sizeof(struct node));
temp->data=d;
temp->next=NULL;
if(rear==NULL)
{
front=rear=temp;
}
else
{
rear->next=temp;
rear=rear->next;
}
}

void deletion()
{
struct node* temp;
if(front==NULL)
cout<<"underflow";
else if(front->next!=NULL)
{
temp=front;
temp=temp->next;
free(front);
front=temp;
}

else
{
free(front);
front=rear=NULL;
}

}

void display()
{
struct node* temp;
temp=front;
while(temp!=NULL)
{
cout<<"\n"<<temp->data;
temp=temp->next;
}}
