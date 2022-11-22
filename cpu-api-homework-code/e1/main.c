#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

int main()
{
	int x = 100;
	int fork_code = fork();

	if (fork_code < 0) {
		fprintf(stderr, "fork failed.\n");
		exit(EXIT_FAILURE);
	} else if (fork_code == 0) {
		printf("Child process id: %d\n", getpid());
		printf("Value of x in chield before change: %d\n", x);
		x = x / 2;
		printf("Value of x in child after change: %d\n", x);
		exit(EXIT_SUCCESS);
	}
	int fork_wait = wait(NULL);
	printf("Parent process id: %d\n", getpid());
	printf("Value of x in parent before change: %d\n", x);
	x = x / 4;
	printf("Value of x in parent after change: %d\n", x);

	return 0;
}