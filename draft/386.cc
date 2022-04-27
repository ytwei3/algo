//
/* 386 - Just Want the Result */
//
#include <cstdio>
using namespace std;


int t;
void out(int a)
{
    printf("%d\n", a);
}
int foo( int a, int b )
{
    while ( a>=b )
    {
        a -=b;
    }
    return a;
}


int main ()
{
    int a, k, n, result;
    while ( ~scanf("%d%d%d", &a, &k, &n) )
    {
        a = foo(a, n);
        result = 1;
        foo(a, k);
        while ( k-- )
        {
            result *= a;
            out(result);
            result = (n&(n-1)) ? (foo(result, n)) : ( result & (n-1) );
        }
        printf("%d\n", result);
    }
    return 0;
}

