//
// 864 - Another A - B Problem
//
#include <stdio.h>
#include <unordered_map>
#include <vector>

int t, n;

int ar[100005];
std::unordered_map<int, int> m;
std::vector<int> v;

int main()
{
    while ( scanf("%d", &t) != EOF )
    {
        while ( t-- )
        {
            m.clear();
            scanf("%d", &n);
            for (int i=1; i<=n; ++i)
                scanf("%d", &ar[i]);

            for (int i=1; i<=n; ++i)
            {
                int tmp = ar[i] - i;
                if ( m.count(tmp) )
                    m[tmp]++;
                else
                {
                    v.push_back(tmp);
                    m[tmp] = 1;
                }
            }

            long long res = 0;
            while ( !v.empty() )
            {
                int tmp = v.back();
                long long k =m[tmp];
                v.pop_back();
                if (k != 1 )
                    res += k*(k - 1) / 2;
            }

            printf("%lld\n", res);
        }
    }

    return 0;
}
