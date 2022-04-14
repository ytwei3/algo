//
/* 758 - Fibonacci Sequence */
//
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;

int t, n; 
long long q, sum, bucket, max;
long long fi[5000001], ar[5000001];
vector<long long> v[5000001];

int main()
{
    fi[0] = 1, fi[1] = 1;
    for (int i=2; i<5000000; ++i)
        fi[i] = fi[i-1] + fi[i-2];

    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d%d", &n, &q);

        max = -1;
        for ( int i=0; i<n; i++ )
            ar[i] = fi[i] % q;

        max = ar[n], bucket = 0;
        while ( max > 0 )
        {
            bucket++;
            max /= q;
        }

        for ( int i=0; i<bucket; ++i )
        {
            int power = pow(q, i);
            int new_array[n];
        }

        sum = 0;
        for (int i=0; i<n; ++i)
            sum += (i+1) * v[i];
    }

    return 0;
}
