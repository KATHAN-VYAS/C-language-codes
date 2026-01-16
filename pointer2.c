#include<stdio.h>
void main()
{
    int a=23;
   
    int *p,**q;
    p=&a;
    q=&p;
    printf("%d\n",a); //value of a
    printf("%d\n",&a); // address of a
    printf("%d\n",p); //p = &a means print address
    printf("%d\n",*p); // value of a
    printf("%d\n",&p); // address where (address of a is stored)
    printf("q details\n");
    printf("%d\n",q); // address of (address of a) 
    printf("%d\n",&q); // where the address of (addres of a is stored)
    printf("%d\n",*q);  // what is pointed at &q = address of a
    printf("%d\n",**q) ; // whats is pointed at address of a = a 
}