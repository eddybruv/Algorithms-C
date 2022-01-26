/**
 * Date: 29-10-2021
 * by eddybruv
 **/

#include <stdio.h>
#include <stdbool.h>

#define MAX 10

int array[MAX];
int end = -1, head = -1;

void command(void);
void enqueue (int );
void dequeue (void);
void printQueue(void);
bool isFull (void);
bool isEmpty(void);

int main(void){
    command();
    int item;
    char command;
    
    for(;;)
    {
        printf("\nEnter command: ");
        scanf(" %c", &command);

        switch (command)
        {
            case 'e':
                printf("Enqueue: ");
                scanf("%d", &item);
                enqueue(item);
                break;
            case 'd':
                dequeue();
                break;
            case 'l':
                printQueue();
                break;
            case 'q':
                printf("Bye! ");
                return 0;
            default: 
                printf("Invalid command.\n");
                break;                
        }
    
    }
    return 0;
}

bool isFull(){
    if(end == MAX - 1)
        return true;
    return false;
}

bool isEmpty(){
    if(head == -1)
        return true;
    return false;
}

void enqueue (int item){
    if(isFull()) //overflow condition
        printf("Queue is full.\n");
    else
    {
        //for the first element
        if(head == -1)
            head = 0;

        end++;
        array[end] = item;
        printf("%d has been added to the queue\n", item);
    }
}

void dequeue(void){
    if(isEmpty()) //underflow condition
        printf("Queue is empty.\n");
    else {
        printf("%d has been removed from the queue\n", array[head]);
        head++;
    }
}

void printQueue(void){
    if(isEmpty())
        printf("Nothing to print, queue is empty\n");
    else {
        printf("Queue: ");

        for(int i = head; i <= end; i++)
            printf("%d ", array[i]);
    }
    printf("\n");
}

void command(void){
    printf("\n============================\n");
    printf("          COMMANDS          \n");
    printf("e -> Enqueue item\n");
    printf("d -> Dequeue item\n");
    printf("l -> Print elements in queue\n");
    printf("q -> quit/exit program\n");
    printf("============================\n");
}
