#include "lexicalParser.h"
#include "lexicalToken.h"
#include "stack.h"
#include "syntaticParser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <regex.h>

#define OPENING_PARENTHESIS -1
#define CLOSING_PARENTHESIS -2

extern LEX_TOKEN * temporaryAST;

int isOperator (STATEMENT microstatement) {
    regex_t regexToDetectOperators;
    regcomp (&regexToDetectOperators, "[~v^|(->)]", 0);
    int result = !regexec (&regexToDetectOperators, microstatement, 0, NULL, 0);
    regfree (&regexToDetectOperators);
    return result;
}

int isProposition (STATEMENT microstatement) {
    regex_t regexToDetectPropositions;
    regcomp (&regexToDetectPropositions, "[m-u]", 0);
    int result = !regexec (&regexToDetectPropositions, microstatement, 0, NULL, 0);
    regfree (&regexToDetectPropositions);
    return result;
}

int isOpeningParentheses (STATEMENT microstatement) {
    regex_t regexToDetectParentheses;
    regcomp (&regexToDetectParentheses, "(", 0);
    int result = !regexec (&regexToDetectParentheses, microstatement, 0, NULL, 0);
    regfree (&regexToDetectParentheses);
    return result;
}

int isClosingParentheses (STATEMENT microstatement) {
    regex_t regexToDetectParentheses;
    regcomp (&regexToDetectParentheses, ")", 0);
    int result = !regexec (&regexToDetectParentheses, microstatement, 0, NULL, 0);
    regfree (&regexToDetectParentheses);
    return result;
}

int analyzeType (STATEMENT microstatement) {

    if (isOpeningParentheses (microstatement))
        return OPENING_PARENTHESIS;

    if (isClosingParentheses (microstatement))
        return CLOSING_PARENTHESIS;

    if (isOperator (microstatement))
        return OPERATOR;

    if (isProposition (microstatement))
        return PROPOSITION;
}

LEX_TOKEN * checkOperation (STATEMENT microstatement, bool priority) {
    LEX_TOKEN * createdToken;
    if (*microstatement == '~')
        createdToken = createToken (OPERATOR, NOT, priority);
    if (*microstatement == '^')
        createdToken = createToken (OPERATOR, AND, priority);
    if (*microstatement == 'v')
        createdToken = createToken (OPERATOR, OR, priority);
    if (*microstatement == '-')
        createdToken = createToken (OPERATOR, COND, priority);
    return createdToken;
}

void debugToken (STATEMENT microstatement, LEX_TOKEN * createdToken) {
    printf ("Analyzing: %s\n", microstatement);
    printf ("Token's type: %d\n", createdToken->type);
    printf ("Token's value: %d\n", createdToken->value);
    printf ("Token's priority: %d\n", createdToken->priority ? 1 : 0);
    puts ("-------------------------");
}

LEX_TOKEN * parseStatement (STATEMENT statement) {

    STATEMENT microstatement = strtok (statement, " "); LEX_TOKEN * createdToken;
    t_stack STACK; initializeStack (&STACK);
    bool priority = false, changed = false;

    while (microstatement) {
        switch (analyzeType (microstatement)) {
            case OPERATOR: changed = true; createdToken = checkOperation (microstatement, priority); break;
            case PROPOSITION: createdToken = createToken (PROPOSITION, *microstatement - 'm', priority); changed = true; break;
            case OPENING_PARENTHESIS: push (&STACK, OPENING_PARENTHESIS); priority = true; changed = false; break;
            case CLOSING_PARENTHESIS: pop (&STACK); priority = false; changed = false; break;
            default: printf ("PARSING ERROR - INVALID TOKEN: %s\n", microstatement); return NULL;
        }

        if (changed) {
            if (DEBUG) debugToken (microstatement, createdToken);
            buildAST (createdToken);
        }
        microstatement = strtok (NULL, " ");
    }

    return temporaryAST;
}