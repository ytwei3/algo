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

struct point
{
    int x, y;
};

vector<point> v;
void partition(int x[], int l, int r, int* p) {

    if (l == r) {

        *p = l;

        return;

    }

    *p = x[l];

    d = l, u = r;

    while (d < u) {

        while (x[u] > pivot) { u --; }

        while (d < r and  x[d] <= pivot) { d ++; }

        if (d < u) {

            swap x[d] and x[u];

        }

    }

    x[l] = x[u];

    x[u] = pivot;

    *p = u;

}


int main()
{
    char a[3] = { '0', '1', '\0' };
    char b[3] = { '0', '1', '2' };

    fputs(a, stdout);
    fputs(b, stdout);

    return 0;
}
