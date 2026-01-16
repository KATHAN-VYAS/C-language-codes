#include<stdio.h>
void main()
{
    int arr[5],f;
    for (int i=0;i<5;i++)
    {
        printf("enter the element ",i);
        scanf("%d",&arr[i]);
    }
    printf("enter the element to find");
    scanf("%d",&f);
    for (int i = 0;i<5;i++)
    {
        if (arr[i]==f)
        {
            printf("the number is in the array");
            break;
        }
        else
        {
            printf("number is not there ");
            break;
        }
    }

}