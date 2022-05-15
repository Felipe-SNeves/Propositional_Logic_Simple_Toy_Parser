#include "node.h"

#ifndef _STACK_H
#define _STACK_H

struct TYPE_STACK {
    int size;
    NODE * top;
};

typedef struct TYPE_STACK t_stack;

int pop (t_stack * STACK);
int push (t_stack * STACK, int value);
void initializeStack (t_stack * STACK);
int isEmpty (const t_stack * STACK);
void showStack (const t_stack * STACK);

#endif