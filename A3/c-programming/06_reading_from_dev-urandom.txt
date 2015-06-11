#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Repeatedly read positive integers and output that many
   random bytes */

int
main()
{
    int in;
    int fd = -1;

    if ((fd = open("/dev/urandom", O_RDONLY)) < 0)
    {
	perror("open()");
	return 0;
    }

    while (scanf("%d", &in) > 0) 
    {
	if (in > 0) 
	{
	    unsigned char *buf = NULL;
	    int i;
	    ssize_t read_ret;

	    buf = (unsigned char *)malloc(in*sizeof(unsigned char));
	    read_ret = read(fd, buf, in);

	    if (read_ret < in)
	    {
		if (read_ret >= 0)
		{
		    fprintf(stderr, "Read fewer than %d bytes. Weird.\n", in);
		}
		else /* read_ret < 0, i.e., error */
		{
		    perror("read");
		    continue;
		}
	    }

	    for(i = 0; i < read_ret; i++) 
	    {
		fprintf(stdout, "0x%02x ", buf[i]); fflush(stdout);
	    }

	    free(buf);
	    fprintf(stdout, "\n"); fflush(stdout);
	}
    }

    return 0;
}
