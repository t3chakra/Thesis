#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Parent fork()-s a child. Then the two of them communicate using a pipe that is
 * created beforehand by the parent. The write end of the pipe is fused with stdout
 * of the parent so that all it needs to do is printf(), and the read end of the pipe
 * is fused with stdin of the child, so all it needs to do is scanf().
 *
 * Any messages we want showing up at the screen from the parent are sent to stderr.
 */

#define	MAX_CHARS_EXCHANGED	10
#define	SLEEP_TIME_SECS		1

int
main()
{
    int pipe_fd[2]; /* Look at man 2 pipe */

    if (pipe(pipe_fd) < 0)
    {
	perror("pipe"); return 0;
    }

    if (fork()) 
    {
	/* Parent */
	unsigned char r; /* Randomly generated char. */
	int urandom_fd = -1; 
	int i; /* Loop variable */
	int read_ret; /* To check return value from read() */

	/* Parent does not need read end of pipe -- close it. */
	close(pipe_fd[0]);

	if (dup2(pipe_fd[1], STDOUT_FILENO) < 0)
	{
	    perror("dup2(parent)"); return 0;
	}

	urandom_fd = open("/dev/urandom", O_RDONLY);
	if(urandom_fd < 0)
	{
	    perror("open(/dev/urandom)"); return 0;
	}

	for (i = 0; i < MAX_CHARS_EXCHANGED; i++)
	{
	    read_ret = read(urandom_fd, &r, sizeof(char));
	    if (read_ret < 1)
	    {
		/* Two cases: read_ret == 0, or read_ret < 0 */
		if (read_ret == 0)
		{
		    fprintf(stderr, "Warning: read(/dev/urandom) returned 0 bytes.\n");
		    fprintf(stderr, "Trying again...\n"); fflush(stderr);
		    i--;
		    continue;
		}
		else
		{
		    perror("read"); return 0;
		}
	    }
	    else
	    {
		int write_ret; /* return from write() */

		r %= ('z' - 'a'); r += 'a';
		printf("%c\n", r); fflush(stdout);

		/* Using stderr in the following print statement so it goes to
		   the screen, and not stdout, which goes to the child.
		*/
		fprintf(stderr, "Parent wrote Char # %d: %c\n", i+1, r); fflush(stdout);
	    }
	}
    }
    else
    {
	/* Child */
	int i; /* Loop variable */

	/* Child does not need write end of pipe -- close it */
	close(pipe_fd[1]);

	if (dup2(pipe_fd[0], STDIN_FILENO))
	{
	    perror("dup2(child)"); return 0;
	}

	for (i = 0; i < MAX_CHARS_EXCHANGED; i++)
	{
	    char c; /* Char that we read from pipe */
	    int scanf_ret; /* return from scanf */

	    scanf_ret = scanf("%s", &c);
		/* Somewhat dangerous use of scanf() -- we give format as a string,
		   but provide space for 1 char. only. This is to cause the \n to
		   be skipped.
		 */
	    if (scanf_ret < 1)
	    {
		if (scanf_ret == 0)
		{
		    fprintf(stderr, "Warning: scanf() read 0 bytes.\n");
		    fprintf(stderr, "Trying again...\n"); fflush(stderr);
		    i--; continue;
		}
		else
		{
		    perror("scanf"); return 0;
		}
	    }
	    else
	    {
		/* Unlike the parent, we can print the following to stdout, as the
		   stdout of the child is still associated with the screen.
		 */
		fprintf(stdout, "Child read Char # %d: %c\n", i+1, c); fflush(stdout);
	    }
	}
    }

    return 0;
}

