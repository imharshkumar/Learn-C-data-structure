#include<stdio.h>
#include<stdlib.h>

struct node
{
int id;
char name[20];
char desig[20];
struct node *next;
struct node *prev;
};
struct node *root;

void createnode(int n);
void insertion();
void deletion();
void display();
void reversal(int n);


void main()
{
int n;
clrscr();
printf("ENTER NO. OF EMPLOYEE DATA ENTERED \n");
scanf("%d",&n);
createnode(n);
printf("Employee data=\n");
display();
insertion();
printf("Employee data afer insertion=\n");
display();
deletion();
printf("Employee data after deletion=\n");
display();
reversal(n);
printf("Employee data after reversal=\n");
display();
getch();

}

void createnode(int n)
{
struct node *t,*p;
int i,d;
char e[20],m[20];

root=(struct node *)malloc(sizeof(struct node));
printf("enter emplyee 1 data ID,NAME,DESIGNATION\n");
scanf("%d",&d);
scanf("%s",&e);
scanf("%s",&m);
root->id=d;

strcpy(root->name,e);
strcpy(root->desig,m);
root->prev=NULL;
root->next=NULL;
t=root;

for(i=1;i<n;i++)
{
p=(struct node *)malloc(sizeof(struct node));
printf("input data for employee=%d\n",i+1);
scanf("%d",&d);
scanf("%s",&e);
scanf("%s",&m);
p->id=d;
strcpy(p->name,e);
strcpy(p->desig,m);
p->next=NULL;
p->prev=t;
t->next=p;
t=t->next;
}
}
void display()
{
//int a=1;
struct node *t;
t=root;
//printf("EMPLOYEE DATA\n");
while(t!=NULL)
{
printf("%d, %s, %s\n",t->id,t->name,t->desig);
t=t->next;
}
}
void insertion()
{
struct node *t,*n;
t=root;
n=(struct node *)malloc(sizeof(struct node));
printf("\nenter new employee data");
scanf("%d%s%s",&n->id,&n->name,&n->desig);
n->prev=NULL;
n->next=t;
t->prev=n;
root=n;
}

void deletion()
{
struct node *t;
t=root;
while(t->next!=NULL)
{
t=t->next;
}
t=t->prev;
t->next=NULL;
}
void reversal(int n)
{
struct node *p,*q;
int i=1,j=n;
int a,x;
char b[20],c[20];
p=q=root;
for(x=1;x<j;x++)
{
q=q->next;
}
while(i<j)
{
a=p->id;
strcpy(b,p->name);
strcpy(c,p->desig);

p->id=q->id;
strcpy(p->name,q->name);
strcpy(p->desig,q->desig);

q->id=a;
strcpy(q->name,b);
strcpy(q->desig,c);

i++;
j--;
p=p->next;
q=q->prev;

}
}