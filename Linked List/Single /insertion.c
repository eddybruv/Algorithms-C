/**
 * Date: 17-11-2021
 * by eddybruv
 * @brief: Single linked list insertion
 * 
 **/


/**
 * Inserting at given position

 *  Such case can be handles using following steps/algorithm:

 *  Move the current pointer upto the position where node to be inserted.
 *  Store current next pointer address to tmp_node next.
 *  Store tmp_node address to current next.
 *
 **/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

void insert_node(struct node**, int , int);
void print_list(struct node *);

int main(void){
    int num_nodes, value, index, position;
    struct node* head = NULL;

    printf("Enter the no. of nodes to create list: ");
    scanf("%d", &num_nodes);

    for (index = 1; index <= num_nodes; index++) {
        printf("Enter node data for position %d in the list:  ", index);
        scanf("%d", &value);
        insert_node(&head, value, index);
    }
    print_list(head);

    printf("\nInsert the element at 1st position:  ");
    scanf("%d", &value);
    insert_node(&head, value, 1);
    // We have inserted one more element, hence num_nodes get increased by 1
    num_nodes += 1;
    print_list(head);

    printf("\nInsert the element at last position:  ");
    scanf("%d", &value);
    insert_node(&head, value, num_nodes + 1);
    // We have inserted one more element, hence num_nodes will get increased by 1
    num_nodes += 1;
    print_list(head);

    printf("\nInsert the element at any position in the list\n");
    printf("Enter the position: ");
    scanf("%d", &position);
    printf("Enter the element value: ");
    scanf("%d", &value);
    insert_node(&head, value, position);
    // We have inserted one more element, hence num_nodes will get increased by 1
    num_nodes += 1;
    print_list(head);
    return 0;
}

void insert_node (struct node **head, int val, int position){
    struct node *cur, *new_node;
    cur = *head;
    new_node = NULL;

    int count = 1;

    new_node = (struct node*) malloc(sizeof(struct node));

    if(new_node == NULL){
        printf("Memory not allocated\n");
        return;
    }

    new_node->data = val;
    new_node->next = NULL;

    if(*head == NULL){
        //List is empty
        *head = new_node;
        return;
    }

    if(position == 1){
        //inserting node at the beginning of the list
        new_node->next = *head;
        *head = new_node;
        return;
    }

    //traversing to find position
    while(cur != NULL && count < position - 1){
        cur = cur->next;
        count++;
    }

    if(position > (count + 1)){
        printf("Position does not exist\n");
        return;
    }

    if(count + 1 == position && cur->next == NULL) {
        //inserting at the end of the list;
        cur->next = new_node;
        return;
    }

    //inserting at a given position
    new_node->next = cur->next;
    cur->next = new_node;
}

void print_list(struct node* head){
    printf("Elements: ");
    
    while (head != NULL){
        printf("%d->", head->data);
        head = head->next;
    }

    printf("NULL\n");
}