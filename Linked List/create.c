/**
 * Date: 14-11-2021
 * by eddubruv
 * 
 * Topic: Creating a linked list.
 **/

/** 
 * A linked list is a data structure used for storing data. A linked list has the following properties:
    - Successive elements are connected by pointers.
    - The last element points to NULL.
    - Can grow or shrink in size during program execution.
    - Can be made as long as needed. (Until system memory exhausts).
    - Doesn’t waste memory space but takes some extra memory for pointers. It allocates memory as it grows.
 **/


struct Node {
    int value;                 //what is being stored in the list
    struct Node *next_node;    //pointer to the next node in the list
};