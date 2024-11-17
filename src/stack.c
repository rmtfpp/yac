#include "stack.h"

struct stack *stack_init(void) // inizializzazione di uno stack
{
    struct stack *st = malloc(sizeof *st);
    if (st)
    {
	st->head = NULL;
	st->stackSize = 0;
    }
    return st;
}


void push(struct stack *Istack, char *value)
{
    struct stack_entry *entry = malloc(sizeof *entry); 
    if (entry)
    {
	entry->data = strdup(value); // duplicazione stringa in data
	entry->next = Istack->head;  // aggiornamenti di next e head
	Istack->head = entry;
	Istack->stackSize++;
    }
    else
    {
	exit(EXIT_FAILURE);
    }
}



char *top(struct stack *Istack)
{
  if (Istack && Istack->head)
    return Istack->head->data;
  else
    return NULL;
}


void pop(struct stack *Istack)
{
  if (Istack->head != NULL)
  {
    struct stack_entry *tmp = Istack->head; // punta a head da deletare
    Istack->head = Istack->head->next;      // cambio head con successiva
    free(tmp->data);                        // rimozione head da deletare
    free(tmp);
    Istack->stackSize--;
  }
}


void clear (struct stack *Istack)
{
  while (Istack->head != NULL)
    pop(Istack);
}


void destroyStack(struct stack **Istack)
{
  clear(*Istack);
  free(*Istack);
  *Istack = NULL;
}


