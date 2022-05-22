#include <stdbool.h>
#ifndef _LEXICAL_TOKEN_H
#define _LEXICAL_TOKEN_H

// TOKEN TYPES
#define OPERATOR 1
#define PROPOSITION 2
#define EXPRESSION 3

// LOGICAL VALUES
#define TRUE 1
#define FALSE 0

// OPERATIONS CODES
#define NOT 0
#define AND 1
#define OR 2
#define COND 3

struct lexical_token {
    int type;
    int value;
    bool priority;
    struct lexical_token * firstChild, * secondChild, * thirdChild;
};

typedef struct lexical_token LEX_TOKEN;

LEX_TOKEN * createToken (int type, int value, bool priority);

#endif