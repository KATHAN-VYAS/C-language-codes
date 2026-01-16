#include<stdio.h>
struct student{
    char name[20];
    int roll_no;
    float marks;

};
void main()
{
    int len;
    printf("enter the no of enteries to be taken ");
    scanf("%d",&len);
    struct student s[10];
    for (int i = 0;i< len ; i++)
    {
        printf("enter name ");
        scanf("%s",&s[i].name);
        printf("enter roll no ");
        scanf("%d",&s[i].roll_no);
        printf("enter marks ");
        scanf("%f",&s[i].marks);

        
    }
    for (int i = 0;i< len ; i++)

    {
        printf(i,"\nname is %s",s[i].name);
        printf("\nroll no is %d",s[i].roll_no);
        printf("\nmarks is %f",s[i].marks);
    }
}