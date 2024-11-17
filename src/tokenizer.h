#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdlib.h>
#include <stdbool.h>

#define OPERATOR_LENGTH 1
#define FUNCTION_LENGTH 3

typedef enum
{
    Operator,
    Function,
    Operand
} token_type;

struct token
{
    char *tkn;
    token_type tt;
};

bool is_operator(char token);

void rmspaces(char* str);

struct token *tokenize(char **expression);

#endif
