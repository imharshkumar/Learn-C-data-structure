#include<stdio.h>
#include<stdlib.h>

struct node
{
  int data;
  struct node *next;
};
struct node *top;

void push();
void pop();
void display();

void main()
{
int ch=0;
clrscr();

while(ch!=4)
{

printf("Enter choice: 1.PUSH  2.POP  3.DISPLAY  4.EXIT\n");
scanf("%d",&ch);
switch(ch)
{
case 1:
  push();
  break;
case 2:
  pop();
  break;
case 3:
  display();
  break;
case 4:
  printf("\nyou exit the program");
  break;
default:
  printf("you entered wrong option.....try again\n");
}

}
getch();
}

void push()
{
struct node *t;
t=(struct node *)malloc(sizeof(struct node));
printf("Enter data: ");
scanf("%d",&t->data);
printf("Item pushed\n\n");
if(top==NULL)
{
t->next=NULL;
top=t;
}
else
{
t->next=top;
top=t;
}

}

void pop()
{
struct node *t;
if(top==NULL)
{
printf("stack is empty\n");
}
else
{
t=top;
top=top->next;
t->next=NULL;
free(t);
}
}

void display()

{
struct node *t;
if(top==NULL)
{
printf("stack is empty\n\n");
}
else
{
printf("stack data:\n");
t=top;
while(t!=NULL)
{
printf("%d\n",t->data);
t=t->next;
}
}
}
