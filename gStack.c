/****************************************************/
/* File: gStack.c                                   */
/* The global stack for the SGML Scanner            */
/* Joel Klemens - 0895223                           */
/****************************************************/

#include "gStack.h"

//creating a new stack 
Stack * initializeStack(){
	//this is going to be the stack that the tokens are pushed onto
	Stack * theStack;

	theStack = malloc(sizeof(Stack));

	theStack->head = NULL;
	theStack->stackSize = 0;

	return theStack;
}

//function for creating a new node in the stack
Node * initializeNode(char * data){
	//this will be the same for every token in the stack
	Node * newNode;
	newNode = malloc(sizeof(Node));

	//not yet pointing to anything else in the stack
	newNode->next = NULL;
	//copy the string into the data of the node
	newNode->data = malloc(sizeof(char) * strlen(data) + 1);
	strcpy(newNode->data, data);

	return newNode; 
}

//function for pushing a new element onto the stack 
void push(Stack * theStack, char * toBeAdded){
	//make sure that the stack is initialized
	if(theStack != NULL){
		//We need to create a node for the data that is being sent to the function, call to init node
		//temp node to hold the node that is being created
		Node * tempToBeAdded;
		Node * tempNode;
		tempToBeAdded = initializeNode(toBeAdded); 
		//we can now make this new node point towards the dummy head of the list
		//if there is currently a head of the list then we need to set it to follow this new node
		if(theStack->head != NULL){
			tempNode = theStack->head;
			//set the new node to point towards the previous head of the list
			tempToBeAdded->next = tempNode;
		}
		//we need to update the list with the new head data
		theStack->head = tempToBeAdded;
		theStack->stackSize++;
	}else{
		//printf("The Stack was NULL, not able to inset node\n");
	}
	return; 
}//end of push

//function to remove the top of the stack
void pop(Stack * theStack){
	//make sure that the stack is initialized
	if(theStack != NULL){
		if(theStack->head != NULL){
			//set the current head to the temp node so it can be freed later
			Node * tempNode;
			tempNode = theStack->head;

			//replace the front of the stack with the next in line
			if(theStack->head->next != NULL){
				theStack->head = theStack->head->next;
			}else{
				theStack->head = NULL; 
			}
			
			//free the node and its data
			free(tempNode->data);
			free(tempNode);
		}
	}
	return; 
}//end of pop

//function to check the node at the top of the stack 
char * getTop(Stack * theStack){
	//if the stack is not null then return the string contained in the head of the stack
	if(theStack != NULL){
		//if the head of the stack is not null
		if(theStack->head != NULL){
			return theStack->head->data; 
		}
	}
	return "Error\n"; 
}//end of get top

//function to check the size of the stack 
int getSize(Stack * theStack){
	//return the size of the stack if the stack is not null
	if(theStack != NULL){
		return theStack->stackSize;
	}
	return 0;
}//end of get size

//function to destroy the stack when the program has finished
void deleteStack(Stack * theStack){
	if(theStack != NULL){
		while(theStack->head != NULL){
			pop(theStack);
		}
		free(theStack); 
	}
	return;
}



