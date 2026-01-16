#include<stdio.h>
struct student
{
    char name[20];
    int roll_no;
    float CPI;
};

void main()
{
    int len;
    printf("enter the number of entery to be entered ");
    scanf("%d",&len);
    struct student *p,s[20];        //write pointer first
    p = s;
    for (int i = 0;i<len;i++)
    {
        printf("enter name\n");
        scanf("%s",&p->name);
        printf("enter roll no \n");
        scanf("%d",&p->roll_no);
        printf("enter CPI \n");
        scanf("%f",&p->CPI);
        p++;
    }
    p =s;       //seting p again to start 
    printf("print:\n");
    for (int i = 0;i<len;i++)
    {
        printf("%s\n",p->name);
        printf("%d\n",p->roll_no);
        printf("%f\n",p->CPI);
        p++;
    }   
}