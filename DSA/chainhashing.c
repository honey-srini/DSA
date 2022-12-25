#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
}*newnode,*prev,*temp;
void insert(struct node table[],int h,int v){    
    temp = table[h].next;
    struct node *newnode = (struct node*)malloc(sizeof(struct node));
    newnode -> data = v;
    newnode -> next = 0;
    if(temp == 0){
        table[h].next = newnode;
    }else{
        while(temp -> next != 0){
            temp = temp -> next;
        }
        temp -> next = newnode;
    }
}
void delete(struct node table[],int h,int v){
    temp = table[h].next;
    if(temp -> data == v){
        table[h].next = temp->next;
        free(temp);
    }else{
        while((temp -> data != v)&&(temp->next != 0)){
            prev = temp;
            temp = temp->next;
        }
        if(temp ->data == v){
            prev -> next = temp -> next;
        }else{
            printf("key not found");
        }
    }
}
void display(struct node table[],int m){
    int i;
    for(i=0;i<m;i++){
        printf("[%d]",i);
        temp = table[i].next;
        while(temp!=0){
            printf("%d--->",temp -> data);
            temp = temp -> next;
        }
        printf("\n");
    }
}
void search(struct node table[],int h,int v){
    int flag = 0;
    temp = table[h].next;
    while((temp -> data != v)&&(temp -> next != 0)){
        temp = temp -> next;
        if(temp -> data == v){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        printf("element found");
    }else{
        printf("element not found");
    }
}
void main(){
    int hashkey,value,size,choice;
    printf("enter the size : ");
    scanf("%d",&size);
    struct node table[size];
    for(int i = 0;i<size;i++){
        table[i].data = -1;
        table[i].next = 0;
    }
    while(1){
        printf("enter 1 to insert\n");
        printf("enter 2 to delete\n");
        printf("enter 3 to display\n");
        printf("enter the choice : ");
        scanf("%d",&choice);
        if(choice >=1 && choice <=3){
            printf("enter the value : ");
            scanf("%d",&value);
            hashkey = value%size;
        }
        switch(choice){
            case 1:
            insert(table,hashkey,value);
            break;
            case 2:
            delete(table,hashkey,value);
            break;
            case 3:
            search(table,hashkey,value);
            break;
            case 4:
            display(table,size);
            break;
            default:
            printf("wrong choice");
        }
    }
}