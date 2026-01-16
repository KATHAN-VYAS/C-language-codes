#include <bits/stdc++.h>
#include<iostream>
//using namespace std;

class queue{
public:
    int front,rear,size;
    unsigned cap;
    int *arr;
};  

queue* createqueue (unsigned cap){
    queue*queue1 = new queue();
    queue1->cap = cap;
    queue1->front = queue1->size =0;
    queue1->rear = cap-1;
    queue1->arr =  new int[(queue1->cap*sizeof(int))];
    return queue1;
}
int isfull (queue* queue1){
    return (queue1->size == queue1->cap);
}
int isempty(queue* queue1)
{
    return(queue1->size ==0);
}
void enqueue(queue* queue1,int item)
{
    if(isfull(queue1))
    {
        return;
    }
    queue1->rear= (queue1->rear +1)%queue1->cap;
    queue1->arr[queue1->rear] = item;
    queue1->size = queue1->size +1;
    std::cout << item << "enque to queue \n" ;
}
int front(queue*queue1){
    if(isempty(queue1))
    {
        return INT_MIN;
    }
    return queue1->arr[queue1->front];
}
int rear(queue*queue1)
{
    if (isempty(queue1))
    {
        return INT_MIN;
    }
    return queue1->arr[queue1->rear];
}

int main()
{
    queue*queue1 = createqueue(100);
    enqueue(queue1,10);
    enqueue(queue1,20);
    enqueue(queue1,30);
    enqueue(queue1,40);
    std::cout << "dequeued from queue \n";
    std::cout << "front item is "<<front(queue1)<<std::endl;
    std::cout << "rear item is " <<rear(queue1)<<std::endl;
    return 0;
}