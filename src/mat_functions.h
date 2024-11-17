#define PLUS '+'
#define MINUS '-'
#define TIMES '*'
#define DIVIDE '/'
#define EXP '^'
#define SIN 's'
#define COS 'c'

#define LEFT_ASSOCIATIVE 'l'
#define RIGHT_ASSOCIATIVE 'r'

typedef struct
{
    char symbol;
    short precedence;
    char associative;
    short arguments;
} Function;

Function sum = {PLUS, 2, LEFT_ASSOCIATIVE, 2};
Function dif = {MINUS, 2, LEFT_ASSOCIATIVE, 2};
Function mul = {TIMES, 3, LEFT_ASSOCIATIVE, 2};
Function dvd = {DIVIDE, 3, LEFT_ASSOCIATIVE, 2};
Function powx = {EXP, 4, RIGHT_ASSOCIATIVE, 2};
Function sinx = {SIN, 1, RIGHT_ASSOCIATIVE, 1};
Function cosx = {COS, 1, RIGHT_ASSOCIATIVE, 1};
