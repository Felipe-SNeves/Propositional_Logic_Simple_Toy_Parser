#include "lexicalToken.h"

#ifndef _LEXICAL_PARSER_H
#define _LEXICAL_PARSER_H

#define DEBUG TRUE

typedef char * STATEMENT;

LEX_TOKEN * parseStatement (STATEMENT statement);

#endif