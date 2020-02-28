#include <stdio.h>
#include <stdbool.h>

typedef struct Pixel {
    int row;
    int col;
    char color;
} Pixel;

typedef Pixel StackEntry;

typedef struct StackNode {
    StackEntry pixel;
    struct StackNode *next;
} StackNode;

typedef struct Stack312 {
    struct StackNode *top;
} Stack312;

// Postcondition: A new stack is created
void makeStack(Stack312 *s);

// Postcondition: Returns true or false
bool isEmpty(Stack312 s);

// Postcondition: Returns true of false
bool isFull(Stack312 s);

// Postcondition: Function places passed StackEntry on top of stack
void push(StackEntry e, Stack312 *s);

// Postcondition: Function returns top StackEntry on stack
StackEntry pop(Stack312 *s);
