// 12 - Yodaness Level
//
// #segment tree, #BIT
#include <stdio.h>
#include <string>
#include <unordered_map>

int t, n, ar[30005], pos;
long long sum, tr[30005];
std::unordered_map<std::string, int> m;

int main ()
{
    while ( ~scanf("%d", &t) )
    {
        while (t--)
        {
            sum = 0;
            char str[30005][25];
            char ss[25];
            m.clear();

            scanf("%d", &n);
            for (int i=0; i<n; ++i)
                scanf("%s", str[i]);

            for (int i=1; i<=n; ++i)
            {
                scanf("%s", ss);
                m[ss] = i;
            }

            for (int i=0; i<n; ++i)
                ar[i] = m[ str[i] ];

            for (int i=0; i<n; ++i)
                tr[i] = 0;

            for (int i=n-1; i>=0; --i)
            {
                pos = ar[i];
                while ( pos )
                {
                    sum += tr[pos];
                    pos -= (pos & -pos);
                }

                pos = ar[i];
                while ( pos <= n )
                {
                    tr[pos] += 1;
                    pos += (pos & -pos);
                }
            }
            printf("%lld\n", sum);
        }
    }
    return 0;
}
