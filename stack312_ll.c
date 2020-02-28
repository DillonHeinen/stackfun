#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stack312_ll.h"

void makeStack(Stack312 *s) {
    s->top = NULL;
}

bool isFalse(Stack312 s) {
    return false;
}

bool isEmpty(Stack312 s) {
    return s.top == NULL;
}

void push(StackEntry e, Stack312 *s) {
    StackNode *temp = (StackNode*) malloc(sizeof(StackNode));
    temp->pixel = e;
    temp->next = s->top;
    s->top = temp;
}

StackEntry pop(Stack312 *s) {
    StackNode *temp = s->top;
    s->top = s->top->next;
    Pixel e = temp->pixel;
    free(temp);
    return e;
}
