#include <cstdio>
#include <algorithm>
#include <list>
using namespace std;

list<int> l;

int main()
{
    int t, n;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        l.push_back(n);
    }
    int i, j, val;
    list<int>::iterator it, it2;
    scanf("%d", &t);
    while(t--) {
        scanf("%d", &n);
        if (n == 1) {
            scanf("%d%d", &i, &val);
            it = next(l.begin(), i);
            l.insert(it, val);
        }
        if (n == 2) {
            scanf("%d", &i);
            it = next(l.begin(), i-1);
            l.erase(it);
        }
        if (n == 3) {
            scanf("%d%d", &i, &j);
            it = next(l.begin(), i-1);
            it2 = next(l.begin(), j);
            reverse(it, it2);
        }
        if (n == 4) {
            scanf("%d", &i);
            printf("%d\n", *next(l.begin(), i-1));
        }
    }
    return 0;
}