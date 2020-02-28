#include <stdio.h>
#include <stdbool.h>
#include "stack312_arr.h"

//Preconditions: Pass pointer to struct of type Stack312
//Postconditios: Stack is initialized
void makeStack(Stack312 *s) {
    s->top = -1;
}

//Preconditions: Pass struct of type Stack312 by value
//Postconditios: Returns true or false
bool isFull(Stack312 s) {
    if(s.top >= 80) {
        return true;
    } else {
        return false;
    }
}

//Preconditions: Pass struct of type Stack312 by value
//Postconditios: Returns true or false
bool isEmpty(Stack312 s) {
    if(s.top == -1) {
        return true;
    } else {
        return false;
    }
}

//Preconditions: Pass stack entry and pointer to a stack
//Postconditions: Pushes entry on stack
void push(StackEntry e, Stack312 *s) {
    s->top++;
    s->elements[s->top] = e;
}

//Preconditions: Pass stack entry and pointer to a stack
//Postconditios: Pops entry on stack
StackEntry pop(Stack312 *s) {
    StackEntry temp = s->elements[s->top];
    s->top--;
    return temp;
}
