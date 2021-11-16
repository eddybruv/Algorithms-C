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

//elements are added to the end of the list but manually
struct node *createnode(int n){
    struct node *new_node;

    new_node = (struct node *)malloc(sizeof(struct node));

    new_node->data = n;
    new_node->next = NULL;

    return new_node;
}

int main(void){
    printf("Creating and traversing linked list\n\n\n");

    struct node *head;

    head = createnode(8);
    head->next = createnode(6);
    head->next->next = createnode(34);
    head->next->next->next = createnode(23);
    head->next->next->next->next = createnode(9);
    head->next->next->next->next->next = createnode(90);

    traverse(head);
    return 0;
}

/**
 * Time Complexity:
 * 
 * O(n), for scanning the list of size n
 * 
 * Space Complexity
 * 
 * O(1), no additional memory required
 **/