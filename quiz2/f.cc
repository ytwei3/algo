//
//
//
//#include <stdio.h>
#include <iostream>
//#include <array>
//#include <string>
#include <vector>
//#include <unoredered_map>
#include <algorithm>
#include <cmath>
#define pi acos(-1)
#define endl "\n"
using namespace std;

struct po
{
    long long x, y;
} p, p0;

int t, n, pos;
const long long INF = 0x3f3f3f3f;
vector<po> v, s;

long long crossProduct(po a, po b, po c)
{
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}
double dis(po a, po b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)*1.0 + (a.y-b.y)*(a.y-b.y)*1.0 );
}
bool cmp(po a, po b)
{
    long long cross = crossProduct(p0, a, b);
    return ( cross > 0 || ( cross == 0 && dis(p0, a) <= dis(p0, b) ) ) ? 1 : 0;
}
void graham()
{
    int m = 1;

    po tmp;
    tmp = v[pos];
    v[pos] = v[0];
    v[0] = tmp;

    s.push_back(p0), s.push_back(v[1]);
    sort( v.begin() + 1, v.end(), cmp );

    for (int i=2; i<v.size(); i++)
    {
        while ( crossProduct(s[m-1], s[m], v[i]) < 0 )
        {
            s.pop_back();
            m--;
        }
        s.push_back(v[i]);
        m++;
    }
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    while ( cin >> t )
    {
        while ( t-- )
        {
            cin >> n;
            if ( n < 3 )
            {
                cout << 0 << endl;
                break;
            }
            p0 = { INF, INF };
            pos = 0;
            for (int i=0; i<n; ++i)
            {
                cin >> p.x >> p.y;
                if ( p.x < p0.x || ( p.x == p0.x && p.y < p0.y ))
                {
                    p0 = p;
                    pos = i;
                }
                v.push_back(p);
            }

            graham();

            cout << s.size() << endl;
            for ( auto i : s )
                cout << i.x << " "
                     << i.y << endl;

            s.clear(), v.clear();
        }
    }
    return 0;
}
