#include <cstdio>

int ar[26];
char str[4];

int find(int x)
{
    while (x != ar[x])
        x = ar[x];
    return ar[x];
}

int main()
{
    int t;
    scanf("%d ", &t);

    int a, b, c, d, len, ans;
    while (t--) {
        fgets(str, sizeof(str), stdin);
        len = str[0] - 64;
        for(int i=0; i<len; i++)
            ar[i] = i;

        while (fgets(str, sizeof(str), stdin) != NULL) {
            if (str[0] == 10)
                break;
            a = str[0] - 65, b = str[1] - 65;
            c = find(a), d = find(b);
            ar[c] = d;
        }

        ans = 0;
        for(int i=0; i<len; i++)
            if (ar[i] == i) ans++;
        printf("%d\n", ans);
        if (t != 0) puts("");
    }
    return 0;
}