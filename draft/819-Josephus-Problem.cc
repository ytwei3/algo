#include <cstdio>
using namespace std;

int main()
{
	int n, m;
	int ar[1001];
	scanf("%d%d", &n, &m);

	for (int i=0; i<=n; i++) {
		ar[i] = i + 1;
	}
	ar[n] = 1;

	int it = m;
	printf("%d", m);
	ar[m-1] = ar[m];
	while (n--) {
		for (int i=0; i<m-1; i++) {
			it = ar[it];
		}
		printf(" %d");
	}
	return 0;
}