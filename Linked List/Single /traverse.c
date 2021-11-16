/**
 * Date: 16-11-2021
 * by eddybruv
 * @brief: program to traverse a single linked list.
 **/

#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;           //data field
    struct node *next;  //pointer to next node
};

void traverse(struct node *head){
    struct node *current;
    current = head;
    int count = 0;

    while (current != NULL){
        count++; //increase node count
        printf("%d->", current->data);
        current = current->next; //sends pointer to next node
    }
    printf("NULL\n");
    printf("Number of nodes: %d", count);
}

//elements are added to the begining of the list
struct node *createnode(struct node* head, int n){
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = n;
    new_node->next = head;

    return new_node;
}

int main(void){
    printf("Creating and traversing linked list\n\n\n");

    struct node *head;
    head = NULL;

    head = createnode(head, 8);
    head = createnode(head, 6);
    head = createnode(head, 34);
    head = createnode(head, 23);
    head = createnode(head, 9);
    head = createnode(head, 90);

    traverse(head);
}