#include "unistd.h"
#define BUFSIZE (1 << 16)

int
main(void)
{
	char *buf;
	read(0, buf, 1);
	write(1, buf, 1);
}
