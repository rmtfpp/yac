#include <stdio.h>
#include <math.h>
#include "mat_functions.h"
#include "stack.h"

int main()
{
    Stack stack;
    initialize(&stack);
    push(&stack, 'ab');
    printf("%d", pop(&stack));
    return 0;
}
