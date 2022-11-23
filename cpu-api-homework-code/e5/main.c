#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int val = 10;
        int fork_code = fork();

        if (fork_code < 0) {
                fprintf(stderr, "Fork failed.\n");
                exit(EXIT_FAILURE);
        } else if (fork_code == 0) {
                printf("Child process %d executing.\n", getpid());
                int child_wait = wait(NULL);
                printf("Wait on child: %d\n", child_wait);
                val *= 2;
                printf("Doubling the value of val: %d\n", val);
                exit(EXIT_SUCCESS);
        }
        int fork_wait = wait(NULL);
        printf("Parent process %d executing.\n", getpid());
        printf("Value of fork: %d\nValue of wait: %d\n", fork_code, fork_wait);

        return EXIT_SUCCESS;
}