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
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stack312_arr.h"

int main(int argc, char *argv[]) {

    Stack312 s;
    makeStack(&s);

    char *fname = (char*) malloc(strlen(argv[1]) + 1);
    strcpy(fname, argv[1]);
//    char fname[] = "C:\\Users\\dillon\\Desktop\\exp.txt";

    FILE *fptr;
    fptr = fopen(fname, "r");

    if (fptr == NULL) {          // checks for empty file
        printf("File Error\n");
        exit(-1);
    } else {
        char buf[BUFSIZ];

        while (fgets(buf, sizeof(buf), fptr)) {               // read in file one line at a time
            char bufferCheck[BUFSIZ];            // prevents false trigger of valid printout
            strcpy(bufferCheck, buf);
            int i = 0;
            int endmarker = 0;
            while((i < strlen(buf)) && (endmarker == 0)) {
                if ((buf[i] == '(') || (buf[i] == '<') || (buf[i] == '[')) {     // checks for an opening brace
                    push(buf[i], &s);
                } else if ((isEmpty(s)) && (((buf[i] == ')') || (buf[i] == '>') || (buf[i] == ']')))) {      // checks for incorrect closing brace
                    if (buf[i] == ')') {
                        buf[strcspn(buf, "\n")] = 0;
                        printf("%s === missing (\n", buf);
                    } else if (buf[i] == '>') {
                        buf[strcspn(buf, "\n")] = 0;
                        printf("%s === missing <\n", buf);
                    } else if (buf[i] == ']') {
                        buf[strcspn(buf, "\n")] = 0;
                        printf("%s === missing [\n", buf);
                    }
                } else if (((buf[i] == ')') || (buf[i] == '>') || (buf[i] == ']'))) {      // checks for general case of incorrect brace
                    char popHold = pop(&s);

                    if ((buf[i] == ')') && (popHold != '(')) {
                        buf[strcspn(buf, "\n")] = 0;
                        printf("%s === missing )\n", buf);
                        endmarker = 1;
                    } else if ((buf[i] == '>') && (popHold != '<')) {
                        buf[strcspn(buf, "\n")] = 0;
                        printf("%s === missing >\n", buf);
                        endmarker = 1;
                    } else if ((buf[i] == ']') && (popHold != '[')) {
                        buf[strcspn(buf, "\n")] = 0;
                        printf("%s === missing ]\n", buf);
                        endmarker = 1;
                    }
                }
                i++;
            }
            if(isEmpty(s) == false) {       // checks for general case of missing brace
                char holder;
                holder = pop(&s);
                if(holder == '(') {
                    buf[strcspn(buf, "\n")] = 0;
                    printf("%s === missing )\n", buf);

                } else if(holder == '<') {
                    buf[strcspn(buf, "\n")] = 0;
                    printf("%s === missing >\n", buf);
                } else if(holder == '[') {
                    buf[strcspn(buf, "\n")] = 0;
                    printf("%s === missing ]\n", buf);
                }
            } else if ((isEmpty(s) == true) && (strcmp(buf, bufferCheck) != 0)){
                printf("%s === valid expression\n", buf);
            }
        }
    } 
    free(fname);
    fclose(fptr);
}
