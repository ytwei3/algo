//
// My scratching file!!
//
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include <array>
#include <cstring>
#include <string>
#include <list>
#include <stack>
#include <queue>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <math.h>
#define endl "\n"
using namespace std;


int n, t;
char str[10001];

int main(void)
{
    float a, b;
    fgets(str, sizeof(str), stdin);
    scanf("%f%f", &a, &b);
    char *data = str;
    int offset;
    int n;
    int sum = 0;

    while (sscanf(data, "%d%n", &n, &offset) == 1)
    {
        sum += n;
        data += offset;
        printf("%c", *data);
        printf("read: %5d; sum = %5d; offset = %5d\n", n, sum, offset);
    }

    printf("sum = %d\n", sum);
    return 0;
}
