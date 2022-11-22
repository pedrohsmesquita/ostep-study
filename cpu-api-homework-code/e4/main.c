#define _GNU_SOURCE
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
        char *env[2] = {"PATH=~/Documents", NULL};
        char *file = "ls";
        char *path = "/bin/ls";
        char *file_arr[3] = {file, "-l", NULL};
        char *path_arr[3] = {path, "-l", NULL};

        printf("Executing execl()\n");
        int fork_code = fork();
        if (fork_code < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(EXIT_FAILURE);                
        } else if (fork_code == 0) {
                execl(path, path, file_arr[1], NULL);
                exit(EXIT_SUCCESS);
        }
        int fork_wait = wait(NULL);

        printf("Executing execlp()\n");
        fork_code = fork();
        if (fork_code < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(EXIT_FAILURE);                
        } else if (fork_code == 0) {
                execlp(file, file, path_arr[1], NULL);
                exit(EXIT_SUCCESS);
        }
        fork_wait = wait(NULL);

        printf("Executing execle()\n");
        fork_code = fork();
        if (fork_code < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(EXIT_FAILURE);                
        } else if (fork_code == 0) {
                execle(path, path_arr[0], path_arr[1], NULL, env);
                exit(EXIT_SUCCESS);
        }
        fork_wait = wait(NULL);

        printf("Executing execv()\n");
        fork_code = fork();
        if (fork_code < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(EXIT_FAILURE);                
        } else if (fork_code == 0) {
                execv(path, path_arr);
                exit(EXIT_SUCCESS);
        }
        fork_wait = wait(NULL);

        printf("Executing execvp()\n");
        fork_code = fork();
        if (fork_code < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(EXIT_FAILURE);                
        } else if (fork_code == 0) {
                execvp(file, file_arr);
                exit(EXIT_SUCCESS);
        }
        fork_wait = wait(NULL);

        printf("Executing execvpe()\n");
        fork_code = fork();
        if (fork_code < 0) {
                fprintf(stderr, "fork failed.\n");
                exit(EXIT_FAILURE);                
        } else if (fork_code == 0) {
                execvpe(file, file_arr, env);
                exit(EXIT_SUCCESS);
        }
        fork_wait = wait(NULL);

        return 0;
}