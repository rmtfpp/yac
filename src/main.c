#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// #include "mat_functions.h"
#include "stack.h"
#define DOUBLE_DIGITS 16
#include "tokenizer.h"

void evaluate(char *exp, struct stack *operator_stack)
{
  while(exp[0] != '\0')
  {
      struct token *token = get_token(exp);
      if (token->tkn)
      {
	  if(token->tt == Function || token->tt = Operator)
	  {
	      push(operator_stack, token->tkn);
	  }
	  else if(token->tt == Operand)
	  {
	      //
	  }
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
    struct stack *operator_stack = stack_init();
    // QUEUE operand TO BE ADDED HERE

    evaluate(exp, operator_stack); // AND operand QUEUE

    return EXIT_SUCCESS;
}
