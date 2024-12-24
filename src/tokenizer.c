#include "tokenizer.h"

char *math_functions[] = {"sin", "cos", "tan", "asn", "acs", "atn", "lne", "exp", "log"};

bool is_operator(char token)
{
    return (token == '+' || token == '-' || token == '*' || token == '/' || token == '^');
}

bool is_openpar(char token)
{
    return token == '(';
}

bool is_closedpar(char token)
{
    return token == ')';
}

bool is_comma(char token)
{
    return token == ',';
}

bool is_function(char *token) {
    char tmp[FUNCTION_LENGTH + 1];  
    strncpy(tmp, token, FUNCTION_LENGTH);
    tmp[FUNCTION_LENGTH] = '\0';
    
    for(int i = 0; i < sizeof(math_functions)/sizeof(math_functions[0]); i++) {
        if(strcmp(tmp, math_functions[i]) == 0) {
            return true;
        }
    }
    return false;
}


int number_size(char *token)
{
    int num_size = 0;

    while(isdigit(token[0]) || token[0] == '.')
    {
	num_size++;
	token++;
    }
    return num_size;
}


bool is_number(char *token)
{
    bool is_number = 0;
    int num_size = number_size(token);
   
    if(num_size != 0)
    {
	return 1;
    }
}

struct token *get_token(char *exp)
{
    while (isspace(*exp)) exp++;
    
    struct token *token = malloc(sizeof *token);
    if (!token) exit(EXIT_FAILURE);
    
    token->tkn = NULL;
    token->tt = Invalid; 

    if(is_operator(exp[0]))
    {
	token->tkn = malloc((OPERATOR_LENGTH + 1) * sizeof(char));
	strncpy(token->tkn, &(exp[0]), OPERATOR_LENGTH);
	token->tkn[OPERATOR_LENGTH] = '\0';
	token->tt = Operator;
    }
    else if(is_function(&(exp[0])))
    {
	token->tkn = malloc((FUNCTION_LENGTH + 1) * sizeof(char));
	strncpy(token->tkn, &(exp[0]), FUNCTION_LENGTH);
	token->tkn[FUNCTION_LENGTH] = '\0';
	token->tt = Function;
    }
    else if(is_number(&(exp[0])))
    {
	token->tkn = malloc((number_size(&(exp[0])) + 1) * sizeof(char));
	strncpy(token->tkn, &(exp[0]), number_size(&(exp[0])));
	token->tkn[number_size(&(exp[0]))] = '\0';
	token->tt = Number;
    }
    else if(is_openpar(exp[0]))
    {
	token->tkn = malloc((OPERATOR_LENGTH + 1) * sizeof(char));
	strncpy(token->tkn, &(exp[0]), OPERATOR_LENGTH);
	token->tkn[OPERATOR_LENGTH] = '\0';
	token->tt = LBracket;
    }
    else if(is_closedpar(exp[0]))
    {
	token->tkn = malloc((OPERATOR_LENGTH + 1) * sizeof(char));
	strncpy(token->tkn, &(exp[0]), OPERATOR_LENGTH);
	token->tkn[OPERATOR_LENGTH] = '\0';
	token->tt = RBracket;
    }
    else if(is_comma(exp[0]))
    {
	token->tkn = malloc((OPERATOR_LENGTH + 1) * sizeof(char));
	strncpy(token->tkn, &(exp[0]), OPERATOR_LENGTH);
	token->tkn[OPERATOR_LENGTH] = '\0';
	token->tt = Comma;
    }
    
    return token;
}
