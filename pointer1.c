#include <stdio.h>
void main()
{
    int a[5]= {10,12,18,15,13};
    int *p;

    p = a;  //BASE ADDRESS OF A IS GIVEN TO P
    for(int i = 0;i<5;i++)
    {
        printf("%d\n",*p);
        p++;
    }
    
}
