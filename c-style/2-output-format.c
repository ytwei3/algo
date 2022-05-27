#include <stdio.h>
#define MAXSIZE 10

int
main(void)
{
	char *buf;
	fgets(buf, MAXSIZE, stdin);
	fputs(buf, stdout);

	while (fgets(buf, MAXSIZE, stdin)) {
		putchar('\n');
		fputs(buf, stdout);
	}
	return 0;
}
