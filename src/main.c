#include <stdio.h>
#include <math.h>
#include "mat_functions.h"
#include "stack.h"

int main()
{
    struct stack *thisStack = stack_init();


    push(thisStack, "foo, bar");
    push(thisStack, "bar, foo");
    printf("%s\n", top(thisStack));
    pop(thisStack);
    printf("%s\n", top(thisStack));
    
    return 0;
}
