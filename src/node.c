#include "node.h"
#include <stdlib.h>

NODE * createNode (int value) {
    
    NODE * newNode = malloc (sizeof (NODE));
    
    if (newNode) {
        newNode->value = value;
        newNode->nodeBelow = NULL;
    }

    return newNode;
}

void insertNodeBelow (NODE * topNode, NODE * bottomNode) {
    topNode->nodeBelow = bottomNode;
}