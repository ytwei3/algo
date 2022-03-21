// 52 - Hanging Nests
//
// find the most unblanced node in a
// Binary Search Tree
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <unordered_map>

std::vector<int> v;
std::unordered_map<int, int> pos;
int unb, res;

int go(std::vector<int> v)
{
    if ( v.size() == 0 )
        return 0;
    else if ( v.size() == 1)
        return 1;
    else
    {
        std::vector<int> small, large;
        for (int i=1; i<v.size(); ++i)
            if (v[i] < v[0] )
                small.push_back(v[i]);
            else
                large.push_back(v[i]);

        int d1 = go(small);
        int d2 = go(large);

        int d = std::abs( d1 - d2 );

        if ( d > unb)
        {
            unb = d;
            res = v[0];
        }
        else if ( d == unb )
            if (pos[ v[0] ] < pos[res] )
                res = v[0];

        if ( d1 > d2 )
            return d1 + 1;
        else
            return d2 + 1; // find depth
    }
}

int main()
{
    int n; // The number of flocks
    scanf("%d", &n);

    for (int i=1; i<=n; ++i)
    {
        int f; // number of birds
        scanf("%d", &f);
        v.resize(f);
        pos.clear();

        for (int j=0; j<f; ++j)
        {
            scanf("%d", &v[j]);
            pos[ v[j] ] = j;
        }

        unb = -1;
        res = -1;
        go(v);

        printf("Flock #%d: %d\n\n", i, res);
    }
    return 0;
}

