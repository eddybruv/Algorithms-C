/**
 * Deletion in a DLL
 * Source: https://www.geeksforgeeks.org/delete-a-node-in-a-doubly-linked-list/
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

/**
 * Function to delete a node in a DLL
 * head --> pointer to the head node pointer.
 * del --> pointer to the node to be deleted
 */

void deleteNode(struct Node** head, struct Node *del){
    //base case
    if(*head == NULL || del == NULL)
        return;

    //if Node to be deleted is head node
    if (*head == del)
        (*head) = del->next;

    //change next if node to be deleted is not the last node
    if(del->next != NULL){
        del->next->prev = del->next;
    }

    //change prev if node to be deleted is not the first node
    if (del->prev == NULL)
        del->prev->next = del->next;

    //free memory occupied by del
    free(del);
    return;
}

/**
 * Delete node at a given position
 * n --> data in the node to be deleted
 */

void deleteAtGivenPos(struct Node **head, int n){
    //if list is empty or an invalid location is given
    if(head == NULL || n <= 0)
        return ;

    struct Node *current;
    current = *head;
    int i;

    //travers upto the node at position 'n' from the beginning
    for(i = 1; current != NULL && i < n; i++)
        current = current->next;

    //if 'n' os greater than the number of nodes
    if (current == NULL)
        return;

    //delete node pointed to by 'current'
    deleteNode(head, current);
}

void push(struct Node **head, int data){
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));

    new_node->data = data;
    
    new_node->prev = NULL;
    new_node->next = (*head);

    if((*head) != NULL)
        (*head)->prev = new_node;
    
    *head = new_node;
}

void printList (struct Node *head){
    while (head != NULL){
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main(void){
    struct Node *head = NULL;

    push(&head, 5);
    push(&head, 2);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    printf("List before: ");
    printList(head);

    deleteAtGivenPos(&head, 4);
    printf("List after: ");
    printList(head);

    return 0;
}