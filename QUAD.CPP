#include<iostream.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int a,b,c,x1,x2,d,q;
cout<<"Enter the value of a,b,c of quadratic eq ax^2+bx+c=0\n";
cin>>a>>b>>c;
d=b*b-4*a*c;
if(d>=0)
{
cout<<"\nRoots are real";
q=sqrt(d);
x1=(-b+q)/2*a;
x2=(-b-q)/2*a;
cout<<"\nroots are "<<x1<<" and "<<x2;
}
else
cout<<"\nRoots are imaginary";
cout<<"\n\n\t\tDaksh";
getch();
}