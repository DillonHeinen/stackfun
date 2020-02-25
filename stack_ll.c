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

void BuildGrid(char fname[], char *grid[], int *numRows, int *numCols) {
    FILE *fptr;
    fptr = fopen(fname, "r");     // open file in read mode

    if (fptr == NULL) {
        printf("File Error\n");
        exit(-1);
    }
    else {
        char buf[BUFSIZ];
        int rowCount = 0;

        while (fgets(buf, sizeof(buf), fptr)) {
            grid[rowCount] = (char*) malloc(strlen(buf));     // allocate space for row of characters
            strcpy(grid[rowCount], buf);
            rowCount++;
        }

        *numRows = rowCount;
        *numCols = strlen(buf);

    }
}

void ShowGrid(char *grid[], int numRows, int numCols) {
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void CheckNeighbors(char *grid[], int row, int col) {

}

void Prompt(int *rowSelect, int *colSelect, char *colorSelect) {
    printf("Enter a row:");
    scanf("%d", rowSelect);
    if (*rowSelect == -1) {
        exit(0);
    }
    printf("Enter a column:");
    scanf("%d", colSelect);
    if (*colSelect == -1) {
        exit(0);
    }
    printf("Enter a color:");
    scanf(" %c", colorSelect);
    printf("\n");
}
