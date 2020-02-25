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

void buildGrid(char fname[], char *grid[], int *numRows, int *numCols) {
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

void showGrid(char *grid[], int numRows, int numCols) {
    for(int i = 0; i < numRows; i++) {
        for(int j = 0; j < numCols; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void checkNeighbors(StackEntry entryUnderTest, char *grid[], Stack312 *s, int numRows, int numCols) {
    int row = entryUnderTest.row;
    int col = entryUnderTest.col;
    char color = entryUnderTest.color;

    if((numRows == 0) && (numCols != 0)) {
        if(grid[row][col + 1] == color) {
            StackEntry e = stackify(grid, (row), (col + 1));
            push(e, s);
        }
    }
    if((numCols == 0) && (numRows != 0)) {
        if(grid[row][col + 1] == color) {
            StackEntry e = stackify(grid, (row + 1), (col));
            push(e, s);
        }
    }
    if(row == 0) {
        if(col == 0) {
            if(grid[row + 1][col] == color) {
                StackEntry e = stackify(grid, (row + 1), (col));
                push(e, s);
            }
            if(grid[row + 1][col + 1] == color) {
                StackEntry e = stackify(grid, (row + 1), (col + 1));
                push(e, s);
            }
            if(grid[row][col + 1] == color) {
                StackEntry e = stackify(grid, (row), (col + 1));
                push(e, s);
            }
        }
        else if(col == (numCols - 1)) {
            if(grid[row][col - 1] == color) {
                StackEntry e = stackify(grid, (row), (col - 1));
                push(e, s);
            }
            if(grid[row + 1][col - 1] == color) {
                StackEntry e = stackify(grid, (row + 1), (col - 1));
                push(e, s);
            }
            if(grid[row + 1][col] == color) {
                StackEntry e = stackify(grid, (row + 1), (col));
                push(e, s);
            }
        }
        else {
            if(grid[row][col - 1] == color) {
                StackEntry e = stackify(grid, (row), (col - 1));
                push(e, s);
            }
            if(grid[row][col + 1] == color){
                StackEntry e = stackify(grid, (row), (col + 1));
                push(e, s);
            }
            if(grid[row + 1][col - 1] == color) {
                StackEntry e = stackify(grid, (row + 1), (col - 1));
                push(e, s);
            }
            if(grid[row + 1][col] == color) {
                StackEntry e = stackify(grid, (row + 1), (col));
                push(e, s);
            }
            if(grid[row + 1][col + 1] == color) {
                StackEntry e = stackify(grid, (row + 1), (col + 1));
                push(e, s);
            }
        }
    }
    else if(col == 0) {
        if(row == (numRows - 1)) {
            if(grid[row - 1][col] == color) {
                StackEntry e = stackify(grid, (row -1 ), (col));
                push(e, s);
            }
            if(grid[row - 1][col + 1] == color) {
                StackEntry e = stackify(grid, (row - 1), (col + 1));
                push(e, s);
            }
            if(grid[row][col + 1] == color) {
                StackEntry e = stackify(grid, (row), (col + 1));
                push(e, s);
            }
        }
        else {
            if(grid[row - 1][col] == color) {
                StackEntry e = stackify(grid, (row - 1), (col));
                push(e, s);
            }
            if(grid[row - 1][col + 1] == color) {
                StackEntry e = stackify(grid, (row - 1), (col + 1));
                push(e, s);
            }
            if(grid[row][col + 1] == color) {
                StackEntry e = stackify(grid, (row), (col + 1));
                push(e, s);
            }
            if(grid[row + 1][col + 1] == color) {
                StackEntry e = stackify(grid, (row + 1), ( + 1));
                push(e, s);
            }
            if(grid[row + 1][col] == color) {
                StackEntry e = stackify(grid, (row + 1), (col));
                push(e, s);
            }
        }
    }
    else if(col == (numCols - 1)) {
        if(row == (numRows - 1)) {
            if(grid[row - 1][col] == color) {
                StackEntry e = stackify(grid, (row - 1), (col));
                push(e, s);
            }
            if(grid[row - 1][col - 1] == color) {
                StackEntry e = stackify(grid, (row - 1), (col - 1));
                push(e, s);
            }
            if(grid[row][col - 1] == color) {
                StackEntry e = stackify(grid, (row), (col - 1));
                push(e, s);
            }
        }
        else {
            if(grid[row - 1][col] == color) {
                StackEntry e = stackify(grid, (row - 1), (col));
                push(e, s);
            }
            if(grid[row - 1][col - 1] == color) {
                StackEntry e = stackify(grid, (row - 1), (col - 1));
                push(e, s);
            }
            if(grid[row][col - 1] == color) {
                StackEntry e = stackify(grid, (row), (col - 1));
                push(e, s);
            }
            if(grid[row + 1][col - 1] == color) {
                StackEntry e = stackify(grid, (row + 1), (col - 1));
                push(e, s);
            }
            if(grid[row + 1][col] == color) {
                StackEntry e = stackify(grid, (row + 1), (col));
                push(e, s);
            }
        }
    }
    else if(row == (numRows - 1)) {
        if(grid[row][col - 1] == color) {
            StackEntry e = stackify(grid, (row), (col - 1));
            push(e, s);
        }
        if(grid[row][col + 1] == color) {
            StackEntry e = stackify(grid, (row), (col + 1));
            push(e, s);
        }
        if(grid[row - 1][col - 1] == color) {
            StackEntry e = stackify(grid, (row - 1), (col - 1));
            push(e, s);
        }
        if(grid[row - 1][col] == color) {
            StackEntry e = stackify(grid, (row - 1), (col));
            push(e, s);
        }
        if(grid[row - 1][col + 1] == color) {
            StackEntry e = stackify(grid, (row - 1), (col + 1));
            push(e, s);
        }
    }
    else {
        if(grid[row - 1][col - 1] == color) {
            StackEntry e = stackify(grid, (row - 1), (col - 1));
            push(e, s);
        }
        if(grid[row - 1][col] == color) {
            StackEntry e = stackify(grid, (row - 1), (col));
            push(e, s);
        }
        if(grid[row - 1][col + 1] == color) {
            StackEntry e = stackify(grid, (row - 1), (col + 1));
            push(e, s);
        }
        if(grid[row][col - 1] == color) {
            StackEntry e = stackify(grid, (row), (col - 1));
            push(e, s);
        }
        if(grid[row][col + 1] == color) {
            StackEntry e = stackify(grid, (row), (col + 1));
            push(e, s);
        }
        if(grid[row + 1][col - 1] == color) {
            StackEntry e = stackify(grid, (row + 1), (col - 1));
            push(e, s);
        }
        if(grid[row + 1][col] == color) {
            StackEntry e = stackify(grid, (row + 1), (col));
            push(e, s);
        }
        if(grid[row + 1][col + 1] == color) {
            StackEntry e = stackify(grid, (row + 1), (col + 1));
            push(e, s);
        }
    }
}

void prompt(int *rowSelect, int *colSelect, char *colorSelect, char *grid[], int numRows, int numCols) {
    printf("Enter a row:");
    scanf("%d", rowSelect);
    if (*rowSelect > numRows - 1) {
        printf("That number was too high");
        exit(0);
    }
    if (*rowSelect == -1) {
        free(grid);
        exit(0);
    }

    printf("Enter a column:");
    scanf("%d", colSelect);
    if (*colSelect > numCols - 1) {
        printf("That number was too high");
        exit(0);
    }
    if (*colSelect == -1) {
        free(grid);
        exit(0);
    }

    printf("Enter a color:");
    scanf(" %c", colorSelect);
    printf("\n");
}

StackEntry stackify(char *grid[], int rowSelect, int colSelect) {
    StackEntry pixel;
    pixel.row = rowSelect;
    pixel.col = colSelect;
    pixel.color = grid[rowSelect][colSelect];
    return pixel;
}
