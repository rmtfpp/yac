#include <stdio.h>
#include <math.h>
#include <stdlib.h>
// #include "mat_functions.h"
#include "stack.h"
#include "queue.h"
#define DOUBLE_DIGITS 16
#include "tokenizer.h"

void evaluate(char *exp, struct stack *operator_stack, struct queue *operand_queue)
{
  while(exp[0] != '\0')
  {
      struct token *token = get_token(exp);
      if (token->tkn)
      {
	  if(token->tt == Function || token->tt == Operator)
	  {
	      push(operator_stack, token->tkn);
	      printf("top of Stack: %s\n", top(operator_stack));
	  }
	  else if(token->tt == Operand)
	  {
	      enqueue(operand_queue, token->tkn);
	      printf("front of Queue: %s\n", front(operand_queue));
	  }
	  exp = exp + strlen(token->tkn);
      }
      else
      {
	  exp++;
      }
  }  
}

int main()
{
    char *exp = "21*(1-3) + 3*sin(PI) - tan(1)'\0'";
    struct stack *operator_stack = stack_init();
    struct queue *operand_queue = queue_init();

    evaluate(exp, operator_stack, operand_queue);

    return EXIT_SUCCESS;
}
