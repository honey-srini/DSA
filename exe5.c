#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
    int data;
    struct node *next;
};

void main(){

/*CREATING A LINKED LIST*/  

    //creating nodes 
    struct node *head, *one=NULL, *two=NULL, *three=NULL, *four=NULL;

    //allocating memory to nodes
    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    four = malloc(sizeof(struct node));

    //assigning values to node data variable
    one->data=1;
    two->data=2;
    three->data=3;
    four->data=4;

    //connecting nodes
    one->next=two;
    two->next=three;
    three->next=four;
    four->next=NULL;

    //assigning head to point at first node
    head  = one;
    printf("Before\n");
    //looping to print node values
    while (head!=NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
    }

    //assigning back head to point at first node one
    head = one;

/*INSERT NEW NODE AT THE BEGINNING*/

    //creating a new node
    struct node *five=NULL;

    //allocating memory to it
    five = malloc(sizeof(struct node));

    //assigning value to data variable
    five->data = 5;

    //assigning new node next pointer to point to one 
    five->next = one;

    //assigning head to point at five which must be our new first node
    head = five;
    printf("\n");
    printf("After inserting at the beginning\n");
    
    //adding a counter variale to number of nodes in liked list
    int counter=0;

    //looping to print node values        
    while (head!=NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
        counter++;
    }
    
    //printing numer of nodes
    printf("Number of nodes: %d\n",counter);

/*INSERT NEW NODE AT THE END*/

    //creating a new node
    struct node *six=NULL;

    //allocating memory to it
    six = malloc(sizeof(struct node));

    //assigning value to data variable
    six->data=6;

    //assigning new node next pointer to NULL since this is last node insertion
    six->next=NULL;

    //assigning back head to first node i.e- five
    head=five;

    //Using for loop to iterate and go to nth node
    int i;
    for ( i = 1; i <=counter; i++)
    {
        //using if statement to assign new node address to previous NULL pointer
        if (head->next==NULL)
        {
            head->next=six;
            // printf("Done\n");
            break;
        }
        head = head->next;
    }
    
    //setting counter to 0 to once again get number of node in linked list
    counter = 0;

    //assigning back head to first node i.e- five
    head = five;
    printf("\n");
    printf("After inserting at the end\n");

    //looping to print node values        
    while (head!=NULL)
    {
        
        printf("%d\n",head->data);
        head = head->next;
        counter++;
    }
    
    //printing numer of nodes
    printf("Number of node: %d\n",counter);
    printf("\n");

/*INSERT NEW NODE AT Nth POSITION*/

    //creating a new node
    struct node *seven=NULL;

    //allocating memory to it
    seven = malloc(sizeof(struct node));

    //assigning value to data variable
    seven->data=7; 

    int pos;
    printf("Enter a position at which new node must be inserted: ");
    scanf("%d",&pos);

    head = five;

    for ( i = 1; i <= counter; i++)
    {
        if (i==(pos-1))
        {
            //head->next points to 2nd element address so assigning it to new node->next
            seven->next=head->next;

            //As new node is inserted at Nth position, head->next should point to new node
            head->next=seven;
            break;
        }
        head = head->next;
    }

    //setting counter to 0 to once again get number of node in linked list
    counter = 0;

    //assigning back head to first node i.e- five
    head = five;

    //looping to print node values        
    while (head!=NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
        counter++;
    }
    
    //printing numer of nodes
    printf("Number of node: %d\n",counter); 
    printf("\n");      

/*DELETE BEGINING NODE*/

    head = five;
    head = head->next;
    free(five);

    //setting counter to 0 to once again get number of node in linked list
    counter = 0;

    //assigning back head to first node i.e- five
    //head = five;

    //looping to print node values    
    printf("After deleting begining of the node\n") ;
    while (head!=NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
        counter++;
    }
    
    //printing numer of nodes
    printf("Number of node: %d\n",counter);
    printf("\n");      

/*DELETE LAST NODE*/    

    //struct node *temp;
    //temp = head;
    head = one;
    for ( i = 1; i < counter; i++)
    {
        if (i==counter-1)
        {
            head->next=NULL;
            head=head->next;
            free(head);
            break;
        }
        head = head->next;
    }
    
    //setting counter to 0 to once again get number of node in linked list
    counter = 0;

    //assigning back head to first node i.e- five
    //head = five;
    head = one;
    //looping to print node values        
    while (head!=NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
        counter++;
    }
    
    //printing numer of nodes
    printf("Number of node: %d\n",counter);    

/*DELETE Nth NODE*/

    int delpos;
    printf("\n");
    printf("Enter node position to delete ");
    scanf("%d",&delpos);

    head = one;

    for ( i = 1; i < counter; i++)
    {
        if (i==(delpos-1))
        {
            struct node *deltemp = head->next;
            head->next=head->next->next;
            deltemp->next=NULL;
            free(deltemp);
        }
        
    }

    //setting counter to 0 to once again get number of node in linked list
    counter = 0;

    //assigning back head to first node i.e- five
    //head = five;
    head = one;
    //looping to print node values        
    while (head!=NULL)
    {
        printf("%d\n",head->data);
        head = head->next;
        counter++;
    }
    
    //printing numer of nodes
    printf("Number of node: %d\n",counter);    

/*SEARCHING AN ELEMENT IN LINKED LIST*/

    int element;
    printf("Enter an element to search for in the linked list: ");
    scanf("%d",&element);

    head=one;
    
    //looping to search element         
    while (head!=NULL)
    {
        if (head->data==element)
        {
            printf("ELEMENT FOUND IN LINKED LIST IS\t");
            printf("%d\n",head->data);
            break;
        }
        // else{
        //     printf("ELEMENT NOT FOUND IN LINKED LIST\t");
        //     break;

        // }
        head = head->next;
    }
}