#include <cstdio>
#include <algorithm>
#define maxn 1000000
#define ll long long
using namespace std;

int len;
int cache[maxn];

int go(ll n)
{
    if (n < maxn)
        if (cache[n])
            return cache[n];

    ll tmp = n;
    len = 1 + go(n & 1 ? 3*n+1 : n/=2);
    if (tmp < maxn)
        cache[tmp] = len;

    return len;
}

int main()
{
    for (int i=0; i<maxn; i++)
        cache[i] = 0;
    cache[1] = 1;

    int a, b, res;
    while (~scanf("%d%d", &a, &b)) {
        printf("%d %d", a, b);

        if (b < a)
            swap(a, b);

        res = 0;
        for (int i=a; i<=b; i++) {
            len = 0;
            res = max(go(i), res);
        }
        printf(" %d\n", res);
    }
    return 0;
}

