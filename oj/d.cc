#include <stdio.h>
#include <list>
#include <queue>
using namespace std;


int main()
{
	int ar[3] = {1, 2, 3};
	for (int i=0; i<3; i++)
	{
		printf("%d ", ar[i]);
		printf(" the value of pointrt: %d\n", *ar+i);
	}
	puts("");

}