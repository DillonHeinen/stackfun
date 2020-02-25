#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack312_arr.h"

int main(int argc, char *argv[]) {

    Stack312 s;
    makeStack(&s);

//    char *fname = (char*) malloc(strlen(argv[1]));
//    strcpy(fname, argv[1]);
    char fname[] = "C:\\Users\\dillon\\Desktop\\exp.txt";

    FILE *fptr;
    fptr = fopen(fname, "r");

    if(fptr == NULL) {
        printf("File Error\n");
        exit(-1);
    } else {
        char buf[BUFSIZ];

        while(fgets(buf, sizeof(buf), fptr)) {
            for(int i = 0; i < strlen(buf); i++) {
                if((buf[i] == '(') || (buf[i] == ')') ||
                   (buf[i] == '<') || (buf[i] == '>') ||
                   (buf[i] == '[') || (buf[i] == ']')) {
                    push(buf[i], &s);
                }
            }
            if(isEmpty(s) == true) {
                printf("There are no expressions to evaluate");
            } else {
                int rightParCount = 0;
                int rightAngCount = 0;
                int rightBraCount = 0;
                int leftParCount = 0;
                int leftAngCount = 0;
                int leftBraCount = 0;

                while(isEmpty(s) != true) {
                    char check = pop(&s);
                    if(check == '(') {
                        leftParCount++;
                    } else if(check == '<') {
                        leftAngCount++;
                    } else if(check == '[') {
                        leftBraCount++;
                    } else if(check == ')') {
                        rightParCount++;
                    } else if(check == '>') {
                        rightAngCount++;
                    } else if(check == ']') {
                        rightBraCount++;
                    }
                }

                if((rightParCount == leftParCount) && (rightAngCount == leftAngCount) && (rightBraCount == leftBraCount)) {
                    printf("%s === valid expression\n", buf);
                } else {
                    printf("%s === missing ", buf);

                    if(rightParCount != leftParCount) {
                        if(rightParCount < leftParCount) {
                            int compare;
                            compare = leftParCount - rightParCount;
                            while(compare != 0) {
                                printf(")");
                                compare--;
                            }
                        } else {
                            int compare;
                            compare = rightAngCount - leftAngCount;
                            while(compare != 0) {
                                printf("(");
                                compare--;
                            }
                        }
                    }
                    if(rightAngCount != leftAngCount) {
                        if(rightAngCount < leftAngCount) {
                            int compare;
                            compare = leftAngCount - rightAngCount;
                            while(compare != 0) {
                                printf(">");
                                compare--;
                            }
                        } else {
                            int compare;
                            compare = rightAngCount - leftAngCount;
                            while(compare != 0) {
                                printf("<");
                                compare--;
                            }
                        }
                    }
                    if(rightBraCount != leftBraCount) {
                        if(rightBraCount < leftBraCount) {
                            int compare;
                            compare = leftBraCount - rightBraCount;
                            while(compare != 0) {
                                printf("]");
                                compare--;
                            }
                        } else {
                            int compare;
                            compare = rightBraCount - leftBraCount;
                            while(compare != 0) {
                                printf("[");
                                compare--;
                            }
                        }
                    }
                    printf("\n");
                }
            }
        }
    }
}
