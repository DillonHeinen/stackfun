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

    Stack312 *s;

    BuildGrid(fname, grid, &numRows, &numCols);

    ShowGrid(grid, numRows, numCols);

    Prompt(&rowSelect, &colSelect, &colorSelect);

    printf("%c\n", grid[rowSelect][colSelect]);

    StackEntry origin = Stackify(grid, rowSelect, colSelect);

    push(origin, s);

    while(s->top != NULL) {
        pop(s);
        checkNeighbors(e);
        grid[e.row][e.col] = colorSelect;
    }
}
