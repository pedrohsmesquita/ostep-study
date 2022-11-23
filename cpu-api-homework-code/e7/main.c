#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int pid = fork();

        if (pid < 0) {
                fprintf(stderr, "Fork failed.\n");
                exit(EXIT_FAILURE);
        } else if (pid == 0) {
                printf("Child process executing.\n");
                printf("Closing stdout\n");
                close(STDOUT_FILENO);
                printf("printing with closed stdout\n");
                printf("the print just doesn't work\n");
                exit(EXIT_SUCCESS);
        }
        int pid_wait = wait(NULL);
        printf("Parent process executing.\n");

        return EXIT_SUCCESS;
}