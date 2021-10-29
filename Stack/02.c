#include <stdbool.h>
#include <stdio.h>

#define STACK_SIZE 100

int array[STACK_SIZE];
int top = 0;

void command(void);
bool isEmpty(void);
bool isFull(void);
void push(int );
int pop(void);
void list(void);

int main(void){
    command();
    int n;
    char command;
    
    for(;;)
    {
        printf("\nEnter command: ");
        scanf(" %c", &command);

        switch (command)
        {
            case 'i':
                printf("Push: ");
                scanf("%d", &n);
                push(n);
                break;
            case 'r':
                pop();
                break;
            case 'l':
                list();
                break;
            case 'q':
                printf("Bye!");
                return 0;
            default: 
                printf("Invalid command.\n");
                break;                
        }
    
    }

    return 0;
}

bool isEmpty(void){
    return top == 0;
}

bool isFull(void){
    return top == STACK_SIZE;
}

void push(int num){
    if(isFull()) //overflow condition
    {
        printf("Stack is full\n");
        return;
    }
    array[top++] = num;
}

int pop(void){
    if(isEmpty()) //underflow condition
    {
        printf("Stack is empty\n");
        return 0;
    }
    printf("%d has been removed from the stack.\n", (array[top - 1]));
    return array[--top];
}

void list(void){
    if(isEmpty())
        printf("Stack is empty\n");
    else {        
        printf("Elements in stack: ");
        for(int i = 0; i < top;i++)
            printf("%d ", array[i]);
        printf("\n");
    }
}

void command(void){
    printf("\n============================\n");
    printf("          COMMANDS          \n");
    printf("i -> insert to stack\n");
    printf("r -> remove last item from stack\n");
    printf("l -> list elements in stack\n");
    printf("q -> quit/exit program\n");
    printf("============================\n");
}