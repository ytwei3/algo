//
/* 228 - Moliu Task */
//
#include <cstdio>
#include <cmath>
using namespace std;


int n, ar[8], res;


int main ()
{
    for (int i=0; i<8; i++)
        ar[i] = 9 * (int)pow(10, i)*(i+1);

    int time = 1;
    int area, num;
    while ( ~scanf("%d", &n) )
    {
        int it = 0;
        while ( n > ar[it] )
            n -= ar[it++];

        area = it + 1;
        num = (n-1) / area + 1;
        for (int i=0; i<it; i++)
            num += 9 * pow(10, i);

        if ( n%area == 0 )
        {
            printf("Case %d : %d\n", time++, num%10);
            continue;
        }

        res = (num / (int)pow(10, area - n%area)) % 10;
        printf("Case %d : %d\n", time++, res);
    }
    return 0;
}

