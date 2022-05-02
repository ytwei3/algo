//
/* 258 - Un-repeating Numbers */
//
#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

int buf[21], len, cnt, now, pr, pos;
long long n;

void check(int st)
{
    for (int i=st; i<cnt; i++)
        if (buf[i] == 10)
            buf[i] = 0, buf[i+1]++;
        else
            break;
}
void go()
{
    while ( buf[now] == buf[pr] )
    {
        pos = max( pr, pos );
        buf[pr]++;
        check(pr);
    }
    if ( now > 2 )
        if ( buf[now-1] == buf[pr-1] )
            now--, pr--, go();

    if ( now < cnt )
    {
        now++, pr++;
        go();
    }
}
void out()
{
    if ( pos > 0 && buf[pos] != 0 )
    {
        buf[pos-1] = 0;
        for (int i=pos-2; i>=0; i--)
            buf[i] = !buf[i+1];
    }

    if ( pos > 0 && buf[pos] == 0 )
    {
        buf[pos-1] = 1;
        for (int i=pos-2; i>=0; i--)
            buf[i] = !buf[i+1];
    }

    if ( buf[cnt] )
        fputs("1", stdout);


    for (int i=cnt-1; i>=0; i--)
        printf("%d", buf[i]);
    putchar('\n');
}

int main ()
{
    while ( ~scanf("%lld", &n) )
    {
        n++;
        for (int i=0; i<=20; i++)
            buf[i] = 0;

        cnt=0;
        while ( n > 0 )
        {
            buf[cnt++] = n%10;
            n /= 10;
        }

        pr = 0, now = 1, pos = 0;
        go();

        out();
    }
    return 0;
}

