//
/* 258 - Un-repeating Numbers */
//
#include <cstdio>
#include <cmath>
using namespace std;

int buf[11], len, cnt;
long long n;

void out()
{
    for (int i=0; i<len; i++)
        printf("%d", buf[i]);
    putchar('\n');
}
void init(long long n)
{
    if ( n/10 > 0 )
        init( n/10 );
    buf[len++] = n%10;
}
void go()
{
    for (int i=0; i<len; i++)
    {
        buf[i]++;
        if (buf[i] == buf[i+1])

    }
}

int main ()
{
    while ( ~scanf("%lld", &n) )
    {
        len = 0;
        for (int i=0; i<=10; i++)
            buf[0] = 0;

        init(n);

        go();

        out();
    }
    return 0;
}

