#include "lexicalToken.h"

#ifndef _SYNTATIC_H
#define _SYNTATIC_H

/*
    - EXPRESSION := PROPOSITION
    - EXPRESSION := OPERATOR EXPRESSION
    - EXPRESSION := EXPRESSION OPERATOR EXPRESION
*/

void buildAST (LEX_TOKEN * newToken);

#endif