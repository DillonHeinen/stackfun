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
    char fname[] = "C:\\Users\\dillo\\Desktop\\file.txt";

    const int MAX_ROWS = 25;

    char *grid[MAX_ROWS];
    int numRows;
    int numCols;
    int rowSelect;
    int colSelect;
    char colorSelect;

    Stack312 s;
    makeStack(&s);

    BuildGrid(fname, grid, &numRows, &numCols);

    while(true) {
        ShowGrid(grid, numRows, numCols);

        Prompt(&rowSelect, &colSelect, &colorSelect, grid);
        /*rowSelect = 0;
        colSelect = 0;
        colorSelect = 'p';*/

        StackEntry entryUnderTest = Stackify(grid, rowSelect, colSelect);

        push(entryUnderTest, &s);

        while (s.top != NULL) {
            entryUnderTest = pop(&s);
            CheckNeighbors(entryUnderTest, grid, &s, numRows, numCols);
            grid[entryUnderTest.row][entryUnderTest.col] = colorSelect;
        }
    }
}
