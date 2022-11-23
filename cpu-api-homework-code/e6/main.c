#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int w_status;
        int pid = fork();

        if (pid < 0) {
                fprintf(stderr, "Fork failed.\n");
                exit(EXIT_FAILURE);
        } else if (pid == 0) {
                printf("Child process executing.\n");
                exit(EXIT_SUCCESS);
        }
        int pid_wait = waitpid(pid, &w_status, WCONTINUED);
        printf("Parent process executing.\n");
        printf("The child has terminated normally? %d\n", WIFEXITED(w_status));

        return EXIT_SUCCESS;
}