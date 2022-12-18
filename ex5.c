// Linked list implementation in C

#include <stdio.h>
#include <stdlib.h>

// Creating a node
struct linkedlist {
  int no;
  struct linkedlist *next;
};

// print the linked list value
void printLinkedlist(struct linkedlist *p) {
  while (p != NULL) {
    printf("%d ", p->no);
    p = p->next;
  }
}

int main() {
  // Initialize nodes
  struct linkedlist *head;
  struct linkedlist *one = NULL;
  struct linkedlist *two = NULL;
  struct linkedlist *three = NULL;

  // Allocate memory
  one = malloc(sizeof(struct linkedlist));
  two = malloc(sizeof(struct linkedlist));
  three = malloc(sizeof(struct linkedlist));

  // Assign value values
  one->no = 10;
  two->no = 20;
  three->no = 30;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // printing node-value
  head = one;
  printLinkedlist(head);
}

