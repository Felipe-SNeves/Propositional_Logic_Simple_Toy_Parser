#ifndef _NODE_H
#define _NODE_H

struct node {
    int value;
    struct node * nodeBelow;
};

typedef struct node NODE;

NODE * createNode (int value);
void insertNodeBelow (NODE * topNode, NODE * bottomNode);

#endif