#include "lexicalToken.h"
#include <stdlib.h>

LEX_TOKEN * createToken (int type, int value, bool priority) {

    LEX_TOKEN * newToken = malloc (sizeof (LEX_TOKEN));

    if (newToken) {
        newToken->type = type;
        newToken->value = value;
        newToken->priority = priority;
        newToken->firstChild = newToken->secondChild = newToken->thirdChild = NULL;
    }

    return newToken;
}