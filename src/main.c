#include <stdio.h>
#include "lexicalParser.h"
#include "lexicalToken.h"

void exploreAST (const LEX_TOKEN * currentNode) {
    while (currentNode) {
        if (currentNode->firstChild)
            exploreAST (currentNode->firstChild);
        if (currentNode->secondChild)
            exploreAST (currentNode->secondChild);
        if (currentNode->thirdChild)
            exploreAST (currentNode->thirdChild);

        printf ("Token's type: %d\n", currentNode->type);
        printf ("Token's value: %d\n", currentNode->value);
        printf ("Token's priority: %d\n", currentNode->priority ? 1 : 0);
        puts ("-------------------------");

        break;
    }
} 

int main () {
    char statement[100] = "( ~ p ^ m ) -> ( q v s ) ^ u";

    LEX_TOKEN * AST = parseStatement (statement);

    /*if (AST) 
        exploreAST (AST);*/

    return 0;
}