#include <stdio.h>
#include <stdbool.h>
#include "stack312_arr.h"

void makeStack(Stack312 *s) {
    s->top = -1;
}

bool isFull(Stack312 s) {
    if(s.top >= 80) {
        return true;
    } else {
        return false;
    }
}

bool isEmpty(Stack312 s) {
    if(s.top == -1) {
        return true;
    } else {
        return false;
    }
}

void push(StackEntry e, Stack312 *s) {
    s->top++;
    s->elements[s->top] = e;
}

StackEntry pop(Stack312 *s) {
    StackEntry temp = s->elements[s->top];
    s->top--;
    return temp;
}
