/*
Write a C program to implement the shell which displays the command
prompt “myshell$”. It accepts the command, tokenize the command line and
execute it by creating the child process. Also implement the additional command
‘typeline’ as
?Typeline
typeline +n filename :- To print first n lines in the file.
typeline -a filename :- To print all lines in the file.

?list
 myshell$ list f dirname :- To print names of all the files in current
 directory.
 myshell$ list n dirname :- To print the number of all entries in the current
 directory
 myshell$ list i dirname :- To print names and inodes of the files in the
 current directory.

?count

 count c filename :- To print number of characters in the file.
 count w filename :- To print number of words in the file.
 count l filename :- To print number of lines in the file.

?search

 myshell$ search a filename pattern :- To search all the occurrence of
 pattern in the file.
 myshell$ search c filename pattern :- To count the number of occurrence
 of pattern in the file.
 myshell$ search f filename pattern :- To display first occurrence of
 pattern in the file.
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <dirent.h>

#define MAX_COMMAND_LENGTH 100
#define MAX_COMMANDS 50

void executeCommand(char *commands[])
{
    pid_t pid = fork();

    if (pid < 0)
    {
        perror("Error while creating child process.");
    }
    else if (pid == 0)
    {
        char path[MAX_COMMANDS] = "/bin/";
        strcat(path, commands[0]);

        execv(path, commands);
    }
    else
    {
        int status;
        wait(&status);
    }
}

void typeline(char *flag, char *filename, char *no_of_lines)
{
    FILE *fp;
    fp = fopen(filename, "r");

    if (strcmp(flag, "+n") == 0)
    {
        int noOfLines = atoi(no_of_lines);
        int i = 0;
        while (i <= noOfLines)
        {
            int ch = fgetc(fp);
            printf("%c", ch);
            if (ch == '\n')
            {
                i++;
            }
        }
    }
    else if (strcmp(flag, "-a") == 0)
    {
        int ch = fgetc(fp);

        while (ch != EOF)
        {
            printf("%c", ch);
            ch = fgetc(fp);
        }
    }

    printf("\n");
}

void list(char *flag, char *dirname)
{
    // fni

    DIR *dr;
    dr = opendir(dirname);
    struct dirent *entry;

    if (dr == NULL)
    {
        printf("Directory not present !");
        return;
    }

    if (strcmp(flag, "f") == 0)
    {
        while ((entry = readdir(dr)) != NULL)
        {
            printf("%s\t", entry->d_name);
        }
        printf("\n");
    }
    else if (strcmp(flag, "n") == 0)
    {
        int n = 0;
        while ((entry = readdir(dr)) != NULL)
        {
            n++;
        }
        printf("No of items : %d\n", n);
    }
    else if (strcmp(flag, "i") == 0)
    {
        while ((entry = readdir(dr)) != NULL)
        {
            printf("%s\t%ld\n", entry->d_name, entry->d_ino);
        }
        printf("\n");
    }
}

void count(char *flag, char *filename)
{
    FILE *fp;
    fp = fopen(filename, "r");

    if (fp == NULL)
    {
        printf("File not present !");
        return;
    }

    int ch;
    if (strcmp(flag, "c") == 0)
    {
        int noOfChars = 0;
        while ((ch = fgetc(fp)) != EOF)
        {
            noOfChars++;
        }
        printf("No of chars : %d\n", noOfChars);
    }
    else if (strcmp(flag, "w") == 0)
    {
        if (ch = fgetc(fp) == EOF)
        {
            printf("No of words : 0\n");
            return;
        }

        int noOfWords = 1;
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == ' ' || ch == '\n')
            {
                while ((ch = getc(fp)) == ' ')
                {
                }
                noOfWords++;
            }
        }
        printf("No of words : %d\n", noOfWords);
    }
    else if (strcmp(flag, "l") == 0)
    {
        int noOflines = 1;
        while ((ch = fgetc(fp)) != EOF)
        {
            if (ch == '\n')
                noOflines++;
        }
        printf("No of lines : %d\n", noOflines);
    }
}

void main()
{
    char line[MAX_COMMAND_LENGTH];
    char *commands[MAX_COMMANDS];

    while (1)
    {
        printf("myshell$ ");
        fgets(line, MAX_COMMAND_LENGTH, stdin);
        if (strcmp(line, "exit\n") == 0 || strcmp(line, "q\n") == 0)
        {
            exit(0);
        }

        int commands_count = 0;
        char *token = strtok(line, " \n");

        while (token != NULL && commands_count < MAX_COMMANDS)
        {
            commands[commands_count] = token;
            token = strtok(NULL, " \n");
            commands_count++;
        }
        commands[commands_count] = NULL;

        if (strcmp(commands[0], "typeline") == 0)
        {
            typeline(commands[1], commands[2], commands[3]);
        }
        else if (strcmp(commands[0], "list") == 0)
        {
            list(commands[1], commands[2]);
        }
        else if (strcmp(commands[0], "count") == 0)
        {
            count(commands[1], commands[2]);
        }
        else
        {
            executeCommand(commands);
        }
    }
}