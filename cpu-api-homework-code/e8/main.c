#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

int main()
{
        int pipefd[2];
        int pid;
        char string[MAX+1] = "ostep book";

        if (pipe(pipefd) == -1) {
                fprintf(stderr, "Error on pipe().\n");
                exit(EXIT_FAILURE);
        }
        pid = fork();
        if (pid < 0) {
                fprintf(stderr, "Fork failed.\n");
                exit(EXIT_FAILURE);
        } else if (pid == 0) {
                close(pipefd[0]);
                write(pipefd[1], string, MAX+1);
                close(pipefd[1]);
                exit(EXIT_SUCCESS);
        }
        wait(NULL);
        pid = fork();
        if (pid < 0) {
                fprintf(stderr, "Fork failed.\n");
                exit(EXIT_FAILURE);
        } else if (pid == 0) {
                char string1[MAX+1];
                close(pipefd[1]);
                read(pipefd[0], string1, MAX+1);
                close(pipefd[0]);
                printf("%s", string1);
                exit(EXIT_SUCCESS);
        }
        wait(NULL);
        close(pipefd[0]);
        close(pipefd[1]);

        return EXIT_SUCCESS;
}