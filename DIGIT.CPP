#include<iostream.h>
#include<conio.h>
void main()
{
clrscr();
int a,b,c,l=0,i=0;
cout<<"Enter any 4 digit no.";
cin>>a;
lable:
b=a%10;
l=l+b;
a=a/10;
i=i+1;
if(i<5)
goto lable;
cout<<"\nSum of digits of 4 digit no.= "<<l;
cout<<"\n\n\t\tShubh aggarwal";
getch();
}