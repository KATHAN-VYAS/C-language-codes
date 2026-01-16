#include<stdio.h>
void main()
{
    int temp;
    int arr[11]={0,1,2,3,4,5,6,7,8,9,10};
   
    for (int j=0;j<6;j++)       //in case of odd number you can set j to floor or int value of 11/2
    {                           // here 5 or 6 both is good to go
       temp=arr[j];
       arr[j]=arr[10-j];
       arr[10-j]= temp;
    }
    printf("reversed arr\n");
    for (int i=0;i<11;i++)
    {
        
        printf(" %d " ,arr[i]);
    }

    
}