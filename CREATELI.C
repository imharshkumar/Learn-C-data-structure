#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node
{
int data;
char name[20];
struct node *next;
};
struct node* root;


void createnode(int n);
void displaynode();
void insertion(int m);
void deletion(int o);
void reversal(int n);


void main()
{
int n,m,o;
clrscr();
printf("enter no. of student data enter = ");
scanf("%d",&n);
createnode(n);
printf("\nData entered in link list\n");
displaynode();
printf("\nenter sr. no. after which insert data\n");
scanf("%d",&m);
insertion(m);
printf("\ndata after insertion\n");
displaynode();
printf("\nenter which serial no. deleted\n");
scanf("%d",&o);
deletion(o);
printf("\nlist after deletion\n");
displaynode();
reversal(n);
printf("\nlist after reversal\n");
displaynode();

getch();
}



void createnode(int n)
{
struct node *temp,*p;
int rn,i;
//char nm[20];

root=(struct node *)malloc(sizeof(struct node));

printf("\nenter data for stdnt 1 NAME AND ROLL NO.\n");
//scanf("%s",&nm);
scanf("%s",&root->name);
scanf("%d",&rn);
root->data=rn;
//root->name=nm;
root->next=NULL;
temp=root;


for(i=1;i<n;i++)
{
p=(struct node *)malloc(sizeof(struct node));

printf("\ninput data for student  %d",i+1);
printf("  NAME AND ROLL NO.\n");
scanf("%s",&p->name);
scanf("%d",&rn);
//p->name=nm;
p->data=rn;
p->next=NULL;

temp->next=p;

temp=temp->next;

}
}

void displaynode()
{
int a=1;

struct node *temp;

if(root==NULL)
{
printf("list is empty");
}
else
{
temp=root;
printf("start");

while(temp!=NULL)
{
printf("-> %d.(%s,%d) ",a,temp->name,temp->data);
temp=temp->next;
a++;
}
printf("->end");
}
}


void insertion(int m)
{
struct node *temp,*n,*x;
int i;
n=(struct node *)malloc(sizeof(struct node));
printf("\nenter new name and roll no.\n");
scanf("%s",&n->name);
scanf("%d",&n->data);

temp=root;
for(i=1;i<m;i++)
{
temp=temp->next;
}
x=temp->next;
temp->next=n;
n->next=x;
}


void deletion(int o)
{
struct node *temp,*x;
int i;
temp=root;
if(o==1)
{
root=root->next;
}
else
{
for(i=2;i<o;i++)
{
temp=temp->next;
}
x=temp->next;
temp->next=x->next;
}}

void reversal(int n)
{
struct node *p,*q;
int i=0,j=n-1,x;

int a;
char b[20];
p=q=root;
while(i<j)
{
for(x=0;x<j;x++)
{
q=q->next;
}
a=p->data;
strcpy(b,p->name);
strcpy(p->name,q->name);
p->data=q->data;
q->data=a;
strcpy(q->name,b);
p=p->next;
q=root;
i++;
j--;
}}