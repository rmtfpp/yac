#include "tokenizer.h"

bool is_operator(char token)
{
    return token == '+' || token == '-' || token == '*' || token == '/' || token == '^';
}

bool is_function(char *token)
{
    char *tmp = malloc(sizeof(char) * FUNCTION_LENGTH);
    strncpy(tmp, token, FUNCTION_LENGTH);

    return (strcmp(tmp, "sin") == 0);
}

struct token *get_token(char *exp)
{
    struct token *token = malloc(sizeof *token);

    if (!token)
    {
	exit(EXIT_FAILURE);
    }

    if(is_operator(exp[0]))
    {
	token->tkn = malloc((OPERATOR_LENGTH + 1) * sizeof(char));
	strncpy(token->tkn, &(exp[0]), OPERATOR_LENGTH);
	token->tt = Operator;
	printf("%s\n", token->tkn);
    }
    else if(is_function(&(exp[0])))
    {
	token->tkn = malloc((FUNCTION_LENGTH + 1) * sizeof(char));
	strncpy(token->tkn, &(exp[0]), FUNCTION_LENGTH);
	token->tt = Function;
	printf("%s\n", token->tkn);
    }
    
    
    return token;
}
