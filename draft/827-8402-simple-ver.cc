#include <cstdio>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> minq;

void generateArray(int n, int m, int seed)
{
	unsigned x = seed;
	for (int i = 0; i < n; i++) {
		x ^= x << 13;
		x ^= x >> 17;
		x ^= x << 5;
		minq.push(x % m + 1);
		// arr[i] = x % m + 1;
	}
}

int main()
{
	freopen("827.in", "r", stdin);

	int n, m, seed;
	while (~scanf("%d%d%d", &n, &m, &seed)) {
		generateArray(n, m, seed);
		
		int cur = minq.top();
		minq.pop();

		while (!minq.empty()) {
			minq.pop();
			minq.push(cur * 2);
			cur = minq.top();
			// printf("cur: %d\n", cur);
			minq.pop();
		}
		printf("%d\n", cur);
	}
	return 0;
}