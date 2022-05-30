//
/* 69 - Recurring Decimals */
//
#include <cstdio>
#include <cmath>
#include <unordered_map>
using namespace std;

int n, l, count[10];
unordered_map<int, int> m;

int main()
{
    while ( ~scanf("%d%d", &n, &l) && (n || l) )
    {
        m.clear();
        m[n] = 0;

        int it = 1, a = n, b[6], c[6], base, cnt;
        while ( 1 )
        {
            for (int i=0; i<10; i++)
                count[i] = 0;

            cnt = 0;
            while ( a>0 )
            {
                count[ a%10 ]++;
                a /= 10;
                cnt++;
            }
            if ( cnt < l )
                count[0] += l - cnt;

            base = 0;
            for (int i=0; i<10; i++)
                for (int j=0; j<count[i]; j++)
                    b[base++] = i;

            base = 0;
            for (int i=10; i>=0; i--)
                for (int j=0; j<count[i]; j++)
                    c[base++] = i;

            for (int i=0; i<l; i++)
            {
                b[i] -= c[i];
                if ( b[i] < 0 )
                    b[i] += 10, b[i+1]--;
            }

            a = 0;
            for (int i=0; i<l; i++)
                a += b[i] * pow(10, i);

            if ( !m.count(a) )
                m[a] = it;
            else
                break;

            it++;
        }
        printf("%d %d %d\n", m[a], a, it - m[a]);
    }
    return 0;
}
