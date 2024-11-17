#include "tokenizer.h"

bool is_operator(char token)
{
    return token == '+' || token == '-' || token == '*' || token == '/' || token == '^';
}

void rmspaces(char* str) {
    char* c = str;
    do {
        while (*c == ' ') {
            ++c;
        }
    } while (*str++ = *c++);
}

struct token *tokenize(char **expression)
{
    struct token *token = malloc(sizeof *token);

    token->tkn = *expression;
    token->tt = Operator;
    return token;
}
