#include <cstdio>
#include <cstdlib>

#define SIZE 100000
#define gc() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, SIZE, stdin), p1 == p2) ? EOF : *p1++)

inline char nc() {
    static char buf[SIZE], *p1, *p2;
    return gc();
}

template<class T>
inline void read(T &x) {
    x = 0;
    char c = nc();

    while (c < '0' || c > '9') {
        c = nc();
        if (c == EOF) exit(0);
    }
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = nc();
}

int main() {
    freopen("../input/1.in", "r", stdin);

    int A, B;
    while (1) {
        read(A), read(B);
        printf("%d\n", A + B);
    }
    return 0;
}