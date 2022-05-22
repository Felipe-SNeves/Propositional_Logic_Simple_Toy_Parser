#include "syntaticParser.h"
#include <stdio.h>

static LEX_TOKEN * lastExpressionCreated = NULL;
static int state = 0;
LEX_TOKEN * temporaryAST;

void buildAST (LEX_TOKEN * leafToken) {
    LEX_TOKEN * newExpression;
    switch (leafToken->type) {
        case OPERATOR:
            puts ("CREATED EXPRESSION!");
            if (state == 0) {
                lastExpressionCreated = createToken (EXPRESSION, leafToken->value * -1, leafToken->priority);
                lastExpressionCreated->firstChild = leafToken;
                state++; break;
            }
            newExpression = createToken (EXPRESSION, leafToken->value, leafToken->priority);
            newExpression->firstChild = lastExpressionCreated;
            newExpression->secondChild = leafToken;
            lastExpressionCreated = newExpression;
            state--;
            break;
        case PROPOSITION:
            puts ("CREATED EXPRESSION!");
            newExpression = createToken (EXPRESSION, leafToken->value, leafToken->priority);
            newExpression->firstChild = leafToken;
            if (lastExpressionCreated && state == 0) {
                lastExpressionCreated->thirdChild = newExpression;
                state++; break;  
            }
            if (lastExpressionCreated && state == 1) {
                lastExpressionCreated->secondChild = newExpression;
                break;
            }
            lastExpressionCreated = newExpression; state++;
    }
    temporaryAST = lastExpressionCreated;
}