//
/* 758 - Fibonacci Sequence */
//
#include <cstdio>

const int radix = 1000;

int t, n, m;
long long q, u, v, w;
int ar[5000001], output[5000001];

void radixSort()
{
    for (int div=1; m/div > 0; div*=radix )
    {
        // counting Sort
        int count[radix] = {0};

        for (int i=0; i<n; i++)
            count[ (ar[i]/div)%radix ]++;

        for (int i=1; i<radix; i++)
            count[i] += count[i-1];

        for (int i=n-1; i>=0; i--)
            output[ --count[ (ar[i]/div)%radix ] ] = ar[i];

        for (int i=0; i<n; i++)
            ar[i] = output[i];
        
    }
}

int main()
{
    scanf("%d", &t);
    while ( t-- )
    {
        scanf("%d%lld", &n, &q);

        ar[0] = ar[1] = m = 1;

        for ( int i=2; i<n; i++ )
        {
            ar[i] = ( ar[i-1] + ar[i-2] ) % q;
            if ( ar[i] > m )
                m = ar[i];
        }

        radixSort();

        long long sum = 0;
        for ( int i=0; i<n; i++ )
            sum += ar[i]%q * (i+1)%q;

        printf("%lld\n", sum % q );
    }
    return 0;
}
