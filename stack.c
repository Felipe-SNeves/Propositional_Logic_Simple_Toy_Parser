#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

int pop (t_stack * STACK) {
    NODE * removedNode = STACK->top;
    STACK->top = removedNode->nodeBelow;
    int returnedValue = removedNode->value;
    free (removedNode);
    return returnedValue;
}

int push (t_stack * STACK, int value) {
    
    NODE * createdNode = createNode (value);

    if (!createdNode)
        return -1;
    
    insertNodeBelow (createdNode, STACK->top);
    STACK->top = createdNode;
    return 0;
}

void initializeStack (t_stack * STACK) {
    STACK->size = 0;
    STACK->top = NULL;
}

int isEmpty (const t_stack * STACK) {
    return !STACK->size;
}

void showStack (const t_stack * STACK) {
    NODE * currentNode = STACK->top;
    while (currentNode) {
        printf ("%d <- ", currentNode->value);
        currentNode = currentNode->nodeBelow;
    }
    puts ("BOTTOM");
}