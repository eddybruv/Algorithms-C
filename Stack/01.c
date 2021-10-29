#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

struct Stack{
    int top;
    int capacity;
    int* array;
};

/**
 * function creates a stack of given capacity
 * Initialises size of stack to zero
 **/

struct Stack* create_stack(int capacity){
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int *)malloc(stack->capacity * sizeof(int));

    return stack;
}

//stack is full when top is equal to the last index
bool isFull(struct Stack* stack){
    return stack->top == stack->capacity - 1;
}

//stack is empty when top is equal to -1
bool isEmpty(struct Stack* stack){
    return stack->top == -1;
}

//funtion to add item to stack. It increases top by 1
void push(struct Stack* stack, int item){
    if(isFull(stack))
        return;
    stack->array[++stack->top] = item;
    printf("%d pushed to stack\n", item);
}

//function to remove an item from stack. Decreases top by 1
int pop(struct Stack* stack){
    if(isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top--];
}

//function to return the top from stack without removing it
int peek(struct Stack* stack){
    if(isEmpty(stack))
        return INT_MIN;
    return stack->array[stack->top];
}

//main function
int main(void){
    int capacity, n;
    printf("Enter capacity of the stack: ");
    scanf("%d", &capacity);
    struct Stack* stack = create_stack(capacity);
    
    printf("Push Items to stack, enter -999 to quit\nPush: ");
    scanf("%d", &n);
    for (int i = 0; i < capacity;i++){
        if(n == -999)
            break;
        push(stack, n);
        printf("Push: ");
        scanf("%d", &n);
    }

    return 0;
}