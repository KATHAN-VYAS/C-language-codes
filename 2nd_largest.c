#include<stdio.h>
void main()
{
    int arr[5]={4,35,74,8,25};
    int temp,i;
    for (int i =0;i<5;i++)
    {
        for (int j =0 ;j<5;j++)         //if you start with j=0 then it will sort in desending order
                                        //for assending order : j = i+1;
        {
            if (arr[j]<arr[i])
            {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    printf("2nd largest number is %d", arr[1]);

   

}