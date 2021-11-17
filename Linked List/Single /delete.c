/**
 * Date: 17-11-2021
 * by eddybruv
 * @brief: Single linked list insertion
 * 
 **/


#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* create(int n){
    struct node* new_node;
    new_node = (struct node*) malloc(sizeof(struct node));

    new_node->data = n;
    new_node->next = NULL;

    return new_node;
}

void traverse(struct node* head){
	struct node* current = head; // current node set to head
	int count = 0; // to count total no of nodes
	printf("\nTraversing the list: \n");

	while(current!=NULL){ 
        //traverse until current node isn't NULL
		
		count++; //increase node count
		printf("%d->",current->data);
		current = current->next; // go to next node
		
	}

    printf("NULL\n");
	
	printf("\nTotal no of nodes : %d\n",count);
}

int main(void){
    struct node *head, *cur, *temp, *prev;
    int count = 1, n, x;

    printf("Enter 0 to stop adding to the list, else enter any integer: ");

    scanf("%d", &n);
    head = create(n);
    scanf("%d", &n);
    
    while (n){
       cur = create(n);
       cur->next = head;
       head = cur;
       scanf("%d", &n); 
    }

    //display list
    traverse(head);

    ///////////////////////  deleting the first node ///////////
    printf("Deleting the first node.........\n");
    temp = head;          //temp is assigned to head
    head = head->next;    //head node is changed (head pointer moves)
    free(temp);           //delete

    //display list
    traverse(head);

    ///////////////////////  deleting the last node ///////////    
    printf("Deleting the last node.........\n");
    temp = head->next;
    prev = head;
    
    while (temp->next != NULL){
        temp = temp->next;
        prev = prev->next;
    }

    //temp now points to the last node
    prev->next = NULL;
    free(temp);
    //display list
    traverse(head);


    ///////////////////////  deleting the any position in the list ///////////
    printf("Enter the position of the node to be deleted: ");
    scanf("%d", &x);
    temp=head->next;
	prev=head;
	while(count!=x-1){
		temp = temp->next;
		prev = prev->next;
		count++;
	}

    //temp now pointing to the node to be deleted
    prev->next = temp->next;
    free(temp);

    //display list
    traverse(head);

    return 0;
}