#include <unistd.h>

#define IN_BUF_SIZE  (1 << 16)
#define OUT_BUF_SIZE (IN_BUF_SIZE * 2 + 2)

int main (void) {
	char in_buf[IN_BUF_SIZE];
	char out_buf[OUT_BUF_SIZE];

	char cbuf;
	
	int n;

	int newline_finished = 0;        // is the last character of the last
	                                 // buf equals '\n'

	char *in_endp;
	char *in_workp;
	char *out_workp;

	while ((n = read(0, in_buf, IN_BUF_SIZE)) > 0) {
		in_endp   = in_buf + (n-1);
		in_workp  = in_buf;
		out_workp = out_buf;

		if (n == 1) {
			newline_finished = 0;
			*out_workp = *in_buf;
			write(1, out_buf, 1);
			break;
		}

		if (newline_finished) {
			newline_finished = 0;
			*(out_workp++) = '\n';
			*(out_workp++) = '\n';
		}

		while (in_workp != in_endp) {
			if ((cbuf = *(in_workp++)) != '\n') {
				*(out_workp++) = cbuf;
			} else {
				*(out_workp++) = '\n';
				*(out_workp++) = '\n';
			}
		}
		if ((cbuf = *(in_workp++)) != '\n') {
			*(out_workp++) = cbuf;
		} else {
			newline_finished = 1;
		}
		write(1, out_buf, out_workp - out_buf);
	}

	if (newline_finished) {
		out_buf[0] = '\n';
		write(1, out_buf, 1);
	}

	return 0;
}