/****************************************************/
/* File: gStack.h                                   */
/* Header file for the global stack                 */
/* Joel Klemens - 0895223                           */
/****************************************************/


#ifndef _GSTACK_
#define _GSTACK_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* Struck for a node in the global stack */
typedef struct stackNode
{
	char * data;
	struct stackNode * next; 
} Node;
	
/* Struct for the head of the stack, this is the stack variable */
typedef struct stackHead
{
	Node * head; 
	int stackSize; 
} Stack;

/* Stack Functions */
//function for creating a new stack
Stack * initializeStack();
//function for creating a new node in the stack
Node * initializeNode(char * data);
//function for pushing a new element onto the stack 
void push(Stack * theStack, char * toBeAdded);
//function to remove the top of the stack
void pop(Stack * theStack); 
//function to check the node at the top of the stack 
char * getTop(Stack * theStack); 
//function to check the size of the stack 
int getSize(Stack * theStack); 
//function to destroy the stack when the program has finished
void deleteStack(Stack * theStack);










#endif