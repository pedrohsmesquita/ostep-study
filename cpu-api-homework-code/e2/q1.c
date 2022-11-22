#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
        int file_descriptor = open("./q1.c", O_RDONLY);
        char character;
        int fork_code = fork();

        if (fork_code < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(EXIT_FAILURE);
        } else if (fork_code == 0) {
                read(file_descriptor, &character, 1);
                printf("Reading from child: %c\n", character);
                close(file_descriptor);
                exit(EXIT_SUCCESS);
        }
        read(file_descriptor, &character, 1);
        printf("Reading from parent: %c\n", character);
        close(file_descriptor);

        return 0;
}