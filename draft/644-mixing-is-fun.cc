#include <cstdio>
#include <cmath>
#include <vector>
#define maxn 50
#define maxm 1226
using namespace std;

int ar[maxm];

int find(int x)
{
	if (ar[x] > 0)
		ar[x] = find(ar[x]);
	return ar[x];
}

int main()
{
	int n, m, a, b, c, d, res;
	while (~scanf("%d%d", &n, &m) && (m || n)) {
		res = 0;
		for (int i=1; i<=n; i++)
			ar[i] = -1;

		while (m--) {
			scanf("%d%d", &a, &b);
			c = find(a), d = find(b);
			printf("c: %d d: %d", c, d);

			ar[c] += ar[d];
			ar[d] = c;
		}

		printf("disjoint set: ");
		for (int i=1; i<=n; i++)
			printf("%d ", ar[i]);
		puts("");

		for (int i=1; i<n; i++)
			res = min(res, ar[i]);
		printf("The value before pow: %d", res);
		res = pow(2, 0-res-1);
		printf("%d\n", res);
	}
	return 0;
}