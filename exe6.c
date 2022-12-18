#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

int front = -1, rear = -1; 
int arraysize = 10;
int arr[10];

void enqueue(){
    if (rear == arraysize-1)
    {
        printf("\nOVERFLOW ! Queue is already full.");
        return;
    }
    else{
        if (front==-1 && rear==-1)
        {
            int value;
            printf("\nEnter data to be added to the queue: ");
            scanf("%d",&value);
            front = rear = 0;
            arr[rear] = value;
            return;
        }
        else
        {
            int value;
            printf("\nEnter data to be added to the queue: ");
            scanf("%d",&value);
            rear+=1;
            arr[rear] = value;
            return;
        }
    }
}

void dequeue(){
    if (front==-1 || front>rear)
    {
        printf("\nUNDERFLOW ! Queue is empty");
    }
    else
    {
        if (front==rear)
        {
            printf("\nDequeue item is %d",arr[front]);
            front = rear = -1;
        }
        else
        {
            printf("\nDequeue item is %d",arr[front]);
            front+=1;
        }
    }
}

void frontval(){
    if (front==-1)
    {
        printf("\nQueue is empty!");
    }
    else
    {
        printf("\nThe front element is %d",arr[front]);
    }
}

void display(){
    if (front==-1)
    {
        printf("\nQueue is empty !");
    }
    else
    {
        int i = front;
        while(i <= rear)
        {
            printf("\n%d",arr[i]);
            i++;
        }
    }
}

void main(){
    printf("1.ENQUEUE\n2.DEQUEUE\n3.FRONT\n4.DISPLAY\n5.EXIT");
    while (1)
    {
        int choice;
        printf("\nEnter your choice: ");
        scanf("%d",&choice);

        switch (choice)
        {
        case 1:
            enqueue();
            break;
        
        case 2:
            dequeue();
            break;

        case 3:
            frontval();
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);
            break;          

        default:
            printf("\nWrong choice. Enter choice again");
            break;
        }   
    }
}
