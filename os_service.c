/**
* Cyrill Castro
* CSC 139-01 
* 
* Homework 2: Part 4
* os_service Program 
**/
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    // Part A Execution: 
    // Argument Checking 
    if (argc < 2) {
        fprintf(stderr, "Error: Please enter at least 2 arguments (file name and command(s))\n");
        exit(-1);
    } else {
        // Printing Results
        printf("\nargc = %d\n", argc);

        for (int i = 1; i < argc; i++) {    
            printf("\nargv[%d] = %s", i, argv[i]);
            printf("\nExecuting command '%s'\n", argv[i]);
            system(argv[i]);
        }
    }

    // Part B Execution:
    // system(ls)
    printf("\nnext call: 'system(ls)'.\n");
    system("ls");

    // system(pwd)
    printf("\nnext call: 'system(pwd)'.\n");
    system("pwd");

    // system(ls; cd mine; ls; cd ..; ls)
    printf("\nnext call: 'system(ls; cd mine; ls; cd ..; ls)'.\n");
    system("ls; cd mine; ls; cd ..; ls");
}