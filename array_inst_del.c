    #include <stdio.h>

    void print (int arr[],int n){
        for(int i =0;i<n;i++){
            printf("%d ",arr[i]);
        }
    }
    void removeelements(int arr[], int index,int size){
        for(int i = index;i<size-1;i++){
            arr[i]= arr[i+1];
        }
        printf("\n");
    }

    void insert(int arr[],int value,int index,int size){
        for(int i=size-1;i>=index;i--){
            arr[i+1] = arr[i];
        }
        printf(" \n");
        arr[index]= value;   
    }
    void main()
    {
        int arr[100]= {1,2,3,4,5};
        int size = 5;
        print(arr,size);
        int value = 10;
        int index = 1;
        insert(arr,value,index,size);
        size+=1;
        print(arr,size);
        removeelements(arr,index,size);
        size -=1;
        print(arr,size);

    }