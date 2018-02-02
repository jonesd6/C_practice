// Simple C program to introduce
// a linked list.

#include <stdlib.h>
#include <stdio.h>

struct node {
    int data;
    struct node * next;
};

void push_node(struct node ** head, int to_add) {
    struct node* new_head = NULL;
    new_head = (struct node*)malloc(sizeof(struct node));

    new_head->data = to_add;
    new_head->next = (*head);
    (*head) = new_head;
    
}

void print_file(struct node * head) {
    while (1) { 
        printf("%d\n",head->data);
        if (head->next == NULL) {
            break;
       }
       head = head->next;
        
 
    }
}

int main() {

    struct node* head = NULL;
    struct node* second = NULL;
    struct node* third = NULL;

    // allocate 3 nodes in the heap
    head = (struct node*)malloc(sizeof(struct node));
    second = (struct node*)malloc(sizeof(struct node));
    third = (struct node*)malloc(sizeof(struct node));

    /* Three blocks have been allocated dynamically.
       We have pointers to these three blocks as first,
       second and third
        head		second		third
         |		|		|
	 |		|		|
      *-------*     *-------*       *-------*
      | # | # |     | # | # |       | # | # |
      *-------*     *-------*       *-------*

     # reresents any random value.
     Data s random because we haven't assigned anythign yet  */

    head->data = 1; //assign data in first node
    head->next = second; // Link first node with the second node

    /* Data has been assigned to data part of the first block
       (block pointed by head). And next pointer of first block
       points to second. So they both are linked.

        head		second		third
         |		|		|
	 |		|		|
      *-------*     *-------*       *-------*
      | 1 | o ----> | # | # |       | # | # |
      *-------*     *-------*       *-------*
    */

    second->data = 2; // assign data to second node
    second->next = third; // Link second node with the third.

    /*

        head		second		third
         |		|		|
	 |		|		|
      *-------*     *-------*       *-------*
      | 1 | o ----> | 2 | o ---->   | # | # |
      *-------*     *-------*       *-------*
    */

    third->data = 3; // assign data to third node.
    third->next = NULL;

    /*

        head		second		third
         |		|		|
	 |		|		|
      *-------*     *-------*       *---------*
      | 1 | o ----> | 2 | o ---->   | 3 | NULL|
      *-------*     *-------*       *---------*
    
    Note that only head is sufficent to represent the whole
    list. We can traverse the complete list by following next
    pointers.
    
    The next pointer of the third block is made NULL to
    indicate that the linked list is terminated here.
    */

    print_file(head);      

    push_node(&head, 1);
    print_file(head);
    return 0;
}

