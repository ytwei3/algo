// 12 - Yodaness Level
//
// #segment tree, #BIT
#include <stdio.h>
#include <string>

int t, n;
std::string s[30005];
long long sum;

int main ()
{
    while ( ~scanf("%d", &t) )
    {
        while (t--)
        {
            sum = 0;
            scanf("%d", &n);
            for (int i=0; i<n; ++i)
                scanf("%*s", &s[i]);

            printf("%lld\n", sum);
        }
    }


    return 0;
}
