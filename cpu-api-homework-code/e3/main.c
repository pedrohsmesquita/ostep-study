#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
        int fork_code = fork();

        if (fork_code < 0) {
                fprintf(stderr, "Fork failed.\n");
                exit(EXIT_FAILURE);
        } else if (fork_code == 0) {
                printf("hello ");
                exit(EXIT_SUCCESS);
        }
        // for (int i = 0; i < 1000000; i++) ;          // method 1
        sleep(1);                                       // method 2
        printf("world");

        return 0;
}