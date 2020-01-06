#include<iostream.h>
#include<conio.h>
#include<stdlib.h>

struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *root;
void insert();
void deletion();
void display();
void inorder(struct node *);
//void preorder(struct node *);
//void postorder(struct node *);
void chart(struct node *,int);

void main()
{
clrscr();
int ch=1;
while(ch!=4)
{
cout<<"\nEnter the operation for bst:\n 1.insertion  2.deletion  3.display 4.exit\n";
cin>>ch;

switch(ch)
{
case 1:
 insert();
 break;
case 2:
 deletion();
 break;
case 3:
 display();
 break;
case 4:
 cout<<"exit...press enter";
}
}
getch();
}


void insert()
{
int a;
struct node *temp;
cout<<"enter value to be input: ";
cin>>a;
temp=(struct node *)malloc(sizeof(struct node));
temp->data=a;
temp->right=temp->left=NULL;

if(root==NULL)
  root=temp;
else
{
struct node *c,*p;
c=root;

while(c!=NULL)
{
p=c;
if(c->data > temp->data)
c=c->left;
else
c=c->right;
}

if(p->data>temp->data)
p->left=temp;
else
p->right=temp;
}
}

void deletion()
{
if(root==NULL)
cout<<"opps...there is no element";
else
{
int z;
cout<<"enter the element want to delete: ";
cin>>z;

struct node *c,*p;
c=p=root;

while(c->data!=z)
{
p=c;

if(z>c->data)
c=c->right;
else
c=c->left;
}

if(c->right==NULL && c->left==NULL)
{
if(c->data > p->data)
p->right=NULL;
else if(c==p)
root=NULL;
else
p->left=NULL;

free(c);
}
else if(c->left==NULL && c->right!=NULL)
{
if(c==p->left)
{
p->left=c->right;
c->right=NULL;
free(c);
}
else if (p==c)
{
root=c->right;
c->right=NULL;
free(c);
}
else
{
p->right=c->right;
c->right=NULL;
free(c);
}
}

else if(c->left!=NULL && c->right==NULL)
{
if(c==p->left)
{
p->left=c->left;
c->left=NULL;
free(c);
}
else if(c==p)
{
root=c->left;
c->left=NULL;
free(c);
}

else
{
p->right=c->left;
c->left=NULL;
free(c);
}
}

else
{
struct node *r,*s;
r=c;
s=c->left;

while(s->right!=NULL)
{
r=s;
s=s->right;
}
if(r==c)
{
c->data=s->data;
r->left=s->left;
s->left=NULL;
free(s);
}
else
{
c->data=s->data;
r->right=s->left;
s->left=NULL;
free(s);
}
}
}
}


void display()
{
cout<<"inorder bst display : ";
inorder(root);
//cout<<"preorder";
//preorder(root);
//cout<<"postorder";
//postorder(root);
//cout<<"chart";
//chart(root,1);
}


void inorder(struct node *d)
{

if(d->left!=NULL)
inorder(d->left);
cout<<d->data<<"  ";
if(d->right!=NULL)
inorder(d->right);
}

void preorder(struct node *d)
{

cout<<d->data;
if(d->left!=NULL)
preorder(d->left);
if(d->right!=NULL);
preorder(d->right);
}
void postorder(struct node *d)
{
if(d->left!=NULL);
postorder(d->left);
if(d->right!=NULL);
postorder(d->right);
cout<<d->data;
}
void chart(struct node *d,int l)
{
if(d!=NULL)
{
chart(d->right,l+1);
cout<<"\n";
for(int i=0;i<l;l++);
cout<<"     ";
cout<<d->data;
chart(d->left,l+1);
}
}