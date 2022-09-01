#include <cstdio>
#include <queue>
using namespace std;

int main()
{
    int t, n, m, k, cur, pos;
    scanf("%d", &t);

    while (t--) {
        scanf("%d%d", &n, &m);
        int ar[10] = {};
        queue<int> qv, qidx;
        for (int i = 0; i < n; i++) {
            scanf("%d", &k);
            qv.push(k), qidx.push(i);
            ar[k]++;
        }

        int time = 0;
        while(1) {
            cur = qv.front(), qv.pop();
            pos = qidx.front(), qidx.pop();

            int canPop(1);
            for (int i = cur+1; i<10; i++) {
                if (ar[i] > 0) {
                    canPop = 0;
                    break;
                }
            }

            if (canPop) {
                time++;
                if (pos == m) {
                    printf("%d\n", time);
                    break;
                }
                ar[cur]--;
            } else {
                qv.push(cur),qidx.push(pos);
            }
        }
    }
    return 0;
}