//
/* 2 - Output Format */
//
#include <cstdio>

char buf[10];

int main()
{
    fgets(buf, sizeof(buf), stdin);
    fputs(buf, stdout);

    while (fgets(buf, sizeof(buf), stdin))
    {
        putchar('\n');
        fputs(buf, stdout);
    }
    return 0;
}
