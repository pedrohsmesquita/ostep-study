#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
        int file_descriptor = open("./a.output", O_RDWR | O_CREAT, S_IRWXU);
        int fork_code = fork();

        if (fork_code < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(EXIT_FAILURE);
        } else if (fork_code == 0) {
                char string = 'l';
                write(file_descriptor, &string, 1);
                close(file_descriptor);
                exit(EXIT_SUCCESS);
        }
        char string = 'i';
        write(file_descriptor, &string, 1);
        close(file_descriptor);

        return 0;
}