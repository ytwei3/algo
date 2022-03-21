#include <stdio.h>
#include <vector>

int t, n, k;
std::vector<int> v;

void toS()
{
    if ( n / 10 != 0)
    {
        v.push_back( n % 10 );
        n /= 10;
    }
}
int main ()
{
    while (scanf("%d", &t) != EOF )
    {
        while (t--)
        {
            scanf("%d%d", &n, &k);
            toS();

            while (k>0 && !v.empty() )
            {
                if ( v.rbegin() > v.rbegin() + 1)
                {
                    v.pop_back();
                    k--;
                }
                else
                {
                    printf("%d", v.back() );
                    v.pop_back();
                }
            }
            printf("\n");
        }
    }

    return 0;
}
