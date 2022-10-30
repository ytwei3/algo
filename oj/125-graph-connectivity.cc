#include <cstdio>

char ar[26], str[4];

char find(char x)
{
    if (x != ar[x])
        ar[x] = find(ar[x]);
    return ar[x];
}

int main()
{
    int t, ans;
    scanf("%d ", &t);

    char a, b, c, d, len;
    while (t--) {
        fgets(str, sizeof(str), stdin);
        len = str[0];
        for(char ch='A'; ch<=len; ch++)
            ar[ch] = ch;

        while (fgets(str, sizeof(str), stdin) != NULL) {
            if (str[0] == '\n')
                break;
            a = str[0], b = str[1];
            c = find(a), d = find(b);
            ar[c] = d;
        }

        ans = 0;
        for(char ch='A'; ch<=len; ch++)
            if (ar[ch] == ch) ans++;
        printf("%d\n", ans);
        if (t != 0) putchar('\n');
    }
    return 0;
}