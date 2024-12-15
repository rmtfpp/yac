#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// #include "mat_functions.h"
#include "stack.h"
#define DOUBLE_DIGITS 16
#include "tokenizer.h"

void evaluate(char *exp)
{
  while(exp[0] != '\0')
  {
      struct token *token = get_token(exp);
      if (token->tkn)
      {
	  exp = exp + strlen(token->tkn);
      }
      else
      {
	  exp++; // spazi vuoti 
      }
  }  
}

int main()
{
    char *exp = "2*(1-3) + 3*sin(PI) - tan(1)'\0'";
    struct stack *thisStack = stack_init();

    evaluate(exp);

    return EXIT_SUCCESS;
}
