#ifndef TOKENIZER_H
#define TOKENIZER_H

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define OPERATOR_LENGTH 1
#define FUNCTION_LENGTH 3

typedef enum
{
    Operator,
    Function,
    Number,
    LBracket,
    RBracket,
    Comma,
    Invalid
} token_type;

struct token
{
    char *tkn;
    token_type tt;
};

bool is_operator(char token);

bool is_function(char *token);

bool is_number(char *token);

struct token *get_token(char *exp, char *expression);

#endif
