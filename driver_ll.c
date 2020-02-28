//life_driver.c
//
//Life Driver program
//Roger Priebe 9/5/2018
//EE 312


/* Student information for project:
 *
 * Replace <NAME> with your name.
 *
 * On my honor, <NAME>, this programming project is my own work
 * and I have not provided this code to any other student.
 *
 * Name: Dillon Heinen
 * email address: dillonheinen@utexas.edu
 * UTEID: deh2486
 * Section 5 digit ID: 16085
 *
 */

//This file is a driver program for the life.c module.
//This program must work with your implementations life.h and life.c
//Do not change the function definitions for populateWorld, showWorld or
//iterateGeneration.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stack312_ll.h"

// Prototypes:

// Preconditions: File exists and grid has been instantiated
// Postconditions: Fills grid with file contents
void buildGrid(char fname[], char *grid[], int *numRows, int *numCols, FILE *fptr);

// Preconditions: Grid has been filled with file contents
// Postconditions: Grid is printed to the screen
void showGrid(char *grid[], int numRows, int numCols);

// Precondtions: Stack has been initialized and grid is filled
// Postconditions: Similar characters are pushed to the stack
void checkNeighbors(StackEntry entryUnderTest, char *grid[], Stack312 *s, int numRows, int numCols);

// Preconditions: File has been read and grid has been printed to screen successfully
// Postconditions: User is prompted and responses are saved in select locations
void prompt(int *rowSelect, int *colSelect, char *colorSelect, char *grid[], int numRows, int numCols, char fname[], FILE *fptr);

// Definitions:

// Postcondition: Converts a char to a StackEntry
StackEntry stackify(char *grid[], int rowSelect, int colSelect);

void buildGrid(char fname[], char *grid[], int *numRows, int *numCols, FILE *fptr) {
   

    if (fptr == NULL) {
        printf("File Error\n");
        exit(-1);
    }
    else {
        char buf[BUFSIZ];
        int rowCount = 0;

        while (fgets(buf, sizeof(buf), fptr)) {
            grid[rowCount] = (char*) malloc(strlen(buf) + 1);     // allocate space for row of characters
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

void checkNeighbors(StackEntry entryUnderTest, char *grid[], Stack312 *s, int numRows, int numCols) {      // evaluates similar characters and converts to stack entry
    int row = entryUnderTest.row;           // Checks for similar characters to popped stack entry
    int col = entryUnderTest.col;
    char color = entryUnderTest.color;

    if((numRows == 0) && (numCols != 0)) {
        if(grid[row][col + 1] == color) {
            StackEntry e = stackify(grid, (row), (col + 1));       // Uses stackify to convert to a struct
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

void prompt(int *rowSelect, int *colSelect, char *colorSelect, char *grid[], int numRows, int numCols, char fname[], FILE *fptr) {     // Prompts the user for a row, column, and color
    printf("Enter a row:");
    scanf("%d", rowSelect);
    if (*rowSelect > numRows - 1) {
        printf("That number was too high");
        exit(0);
    }
    if (*rowSelect == -1) {
        for(int i = 0; i < numRows; i++) {
           free(grid[i]);                // deallocate heap space
        }
        free(fname);
        fclose(fptr);
        exit(0);
    }

    printf("Enter a column:");
    scanf("%d", colSelect);
    if (*colSelect > numCols - 1) {
        printf("That number was too high");
        exit(0);
    }
    if (*colSelect == -1) {
        for(int i = 0; i < numRows; i++) {
            free(grid[i]);                // deallocate heap space
        }
        free(fname);
        fclose(fptr);
        exit(0);
    }

    printf("Enter a color:");
    scanf(" %c", colorSelect);
    printf("\n");
}

StackEntry stackify(char *grid[], int rowSelect, int colSelect) {         // converts a character to a stack entry using grid info
    StackEntry pixel;
    pixel.row = rowSelect;
    pixel.col = colSelect;
    pixel.color = grid[rowSelect][colSelect];
    return pixel;
}



int main(int argc, char *argv[]) {
//    printf("Hello, World!\n");
//    return 0;

    char *fname = (char*) malloc(strlen(argv[1]) + 1);
    strcpy(fname, argv[1]);
//    char fname[] = "C:\\Users\\Dillon\\Desktop\\file.txt";

    FILE *fptr;
    fptr = fopen(fname, "r");     // open file in read mode

    const int MAX_ROWS = 25;        // Constraint defined in assignment documents

    char *grid[MAX_ROWS];
    int numRows;
    int numCols;
    int rowSelect;
    int colSelect;
    char colorSelect;

    Stack312 s;
    makeStack(&s);

    buildGrid(fname, grid, &numRows, &numCols, fptr);

    while(true) {        // Infinite loop to continuously implement functions for flood fill
        showGrid(grid, numRows, numCols);

        prompt(&rowSelect, &colSelect, &colorSelect, grid, numRows, numCols, fname, fptr);
        /*rowSelect = 0;
        colSelect = 0;
        colorSelect = 'p';*/

        StackEntry entryUnderTest = stackify(grid, rowSelect, colSelect);

        push(entryUnderTest, &s);

        while (s.top != NULL) {        // loop to pop all entries off stack
            entryUnderTest = pop(&s);
            if ((numRows != 0) || (numCols != 0)) {
                checkNeighbors(entryUnderTest, grid, &s, numRows, numCols);
            }
            grid[entryUnderTest.row][entryUnderTest.col] = colorSelect;
        }
    }
}
