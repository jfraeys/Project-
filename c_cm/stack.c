/****************************************************/
/* File: stack.c                                    */
/* Implementation of a stack data structure of      */
/* strings.                                         */
/* Jeremie Fraeys and Joel Klemens                  */
/****************************************************/

#include "stack.h"

struct stack_t *createStack(){
    struct stack_t *newStack = malloc(sizeof *newStack);
    if(newStack){
        newStack->head = NULL;
        newStack->size = 0;
    }

    return newStack;
}

struct stack_node *initStackData(){
    struct stack_node *node = malloc(sizeof(struct stack_node));
    node->data = NULL;
    node->next = NULL;

    return node;
}

void push(struct stack_t *stack, char* value){
    struct stack_node *node = initStackData();

    if(node){
        node->data = malloc(strlen(value) + 1);

        if(node->data){
          strcpy(node->data, value);
          node->next = stack->head;
          stack->head = node;
          stack->size++;
        }
    }
}

void pop(struct stack_t *stack){
    if(stack->head){
        struct stack_node *temp = stack->head;
        stack->head = stack->head->next;
        stack->size--;
        free(temp->data);
        free(temp);
    }
}

char* top(struct stack_t *stack){
    if(stack && stack->head)
        return stack->head->data;
    return NULL;
}

void display(struct stack_t *stack){
    if(stack->head){
        struct stack_node *temp = stack->head;

        while(temp){
            fprintf(stderr, "%s\n", temp->data);
            temp = temp->next;
        }
    }
}

void destroy(struct stack_t *stack){
    while(stack->head != NULL)
        pop(stack);

    free(stack);
    stack = NULL;
}
