/**
 * Cyrill Castro
 * CSC 139-01
 * 
 * Homework 5
 * Command Line Interpreter 
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LIST 15     // variable to define the amount of commands
#define MAX_INPUT 1000  // variable to define the amount of command arguments inputted by user

// List of all commands supported by cli
char * cmds[MAX_LIST] = 
    {
        "cd",
        "execv",
        "exit",
        "fork",
        "gcc",
        "ls",
        "man",
        "more",
        "mv",
        "rm",
        "pwd",
        "sh",
        "touch",
        "which",
        "$PATH"
    };

char rawInput[MAX_INPUT];     // holds each string temporarily, to pass to the parsed str array
char* token;                    // holds the raw input during tokenizing 
char* parsedStr[MAX_INPUT];     // array to hold all strings after parsing  
int currIndex = 0;              // index for parsed string array

int main(int argc, char* argv[]) {
    if (argc == 1) {
        fprintf(stderr, "Error: Please print at least two arguments (filename and command(s))\n");
        exit(-1);
    } else {
        // Identify itself, the author, and the release date. 
        printf("Command Line Interpreter (cli) by Cyrill Castro, 4/09/2020\n");
        
        // Print the list of predefined commands 
        printf("Legal commands: ");
        for (int i = 0; i < MAX_LIST; i++) {
            printf(" %s", cmds[i]);
        }
        
        rawInput[0] = 0;          // null-terminated string

        // Execute all commands listed after the cli invocation 
        printf("\n%d string(s) passed to argv[]\n", argc);
        for (int i = 1; i < argc; i++) {
            printf("next string is '%s'\n", argv[i]);
            strcat(rawInput, argv[i]);
            strcat(rawInput, " ");
            printf("new string is '%s'\n", rawInput);
        }

        // tokenize the rawInput and delimit after every comma, add to the array of parsed strings, update the index 
        token = strtok(rawInput, ",;");
        
        while (token != NULL) {            
            parsedStr[currIndex] = token;

            token = strtok(NULL, ",;");
            currIndex++;
        }

        // trim leading space in strings to prepare them for string comparison later on
        for (int i = 0; i < currIndex; i++) {
            while (isspace(*parsedStr[i])) {
                parsedStr[i]++;
            }
        }

        // then loop through the array of parsed strings, check if the command is predefined by comparing the strings
        // up to a certain number of characters (based on how many characters are in the cmd[checkCmd]). Then print 
        // the appropriate messages and do a system call, if applicable. Lastly, resert variables. 
        int checkCmd = 0;
        for (int i = 0; i < currIndex; i++) {
            while (checkCmd < MAX_LIST) {
                if (strncmp(cmds[checkCmd], parsedStr[i], strlen(cmds[checkCmd])) == 0) {
                    printf("cmd '%s' is one of the predefined.\n", parsedStr[i]);
                    system(parsedStr[i]);
                    checkCmd = 0;
                    break;
                }
                checkCmd++;
            } 

            if (checkCmd >= MAX_LIST) {
                printf("cmd '%s' is not one of the predefined.\n", parsedStr[i]);
                printf("Legal commands: ");
                for (int i = 0; i < MAX_LIST; i++) {
                    printf(" %s", cmds[i]);
                }
                printf("\n");
                checkCmd = 0;
            }
        }

        // print out the current working directory
        system("pwd");
    }
}