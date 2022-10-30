#include <cstdio>
#include <unistd.h>
#define IN_SIZE 1 << 16
#define OUT_SIZE 1 << 18

int main()
{
	char buf[IN_SIZE], obuf[OUT_SIZE];
	freopen("2.in", "r", stdin);
	int in_size = read(0, buf, IN_SIZE);
	int out_size = 0;

	for (int i=0; i<in_size; i++) {
		if ((buf[i] < '0' || buf[i] > '9') && buf[i+1] && i+1 < in_size) continue;
		obuf[out_size++] = '\n';
		obuf[out_size++] = '\n';
		obuf[out_size++] = buf[i];
	}
	obuf[out_size++] = '\n';
	write(1, obuf+2, out_size);
	return 0;
}
