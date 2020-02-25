#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "stack312_ll.h"

int main(int argc, char *argv[]) {
//    printf("Hello, World!\n");
//    return 0;

//    char *fname = (char*) malloc(strlen(argv[1]));
//    strcpy(fname, argv[1]);
    char fname[] = "C:\\Users\\Dillon\\Desktop\\file.txt";

    const int MAX_ROWS = 25;

    char *grid[MAX_ROWS];
    int numRows;
    int numCols;
    int rowSelect;
    int colSelect;
    char colorSelect;

    Stack312 s;
    makeStack(&s);

    buildGrid(fname, grid, &numRows, &numCols);

    while(true) {
        showGrid(grid, numRows, numCols);

        prompt(&rowSelect, &colSelect, &colorSelect, grid, numRows, numCols);
        /*rowSelect = 0;
        colSelect = 0;
        colorSelect = 'p';*/

        StackEntry entryUnderTest = stackify(grid, rowSelect, colSelect);

        push(entryUnderTest, &s);

        while (s.top != NULL) {
            entryUnderTest = pop(&s);
            if ((numRows != 0) || (numCols != 0)) {
                checkNeighbors(entryUnderTest, grid, &s, numRows, numCols);
            }
            grid[entryUnderTest.row][entryUnderTest.col] = colorSelect;
        }
    }
}
