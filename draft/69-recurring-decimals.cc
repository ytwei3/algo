//
/* 69 - Recurring Decimals */
//
#include <cstdio>
using namespace std;

int n, l, buf[7], count[10], a[7], b[7];

int main()
{
    while ( ~scanf("%d%d", &n, &l) && (n || l) )
    {
        for (int i=0; i<10; i++)
            count[i] = 0;

        for (int i=0; i<l; i++)
            count[n%10]++, n/=10;

        for (int i=0, j=0; i<10; i++)
            if ( count[i]>0 )
                a[j++] = count[i];

        for (int i=0; i<l; i++)
            printf("%d", a[i] );
        printf("\n");

    }
    return 0;
}
