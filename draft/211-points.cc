//
// My sample file
//
//#include <stdio.h>
#include <iostream>
//#include <array>
//#include <string>
#include <vector>
//#include <unoredered_map>
#include <algorithm>
#include <math.h>
#define endl "\n"
using namespace std;

struct point
{
    int x, y;
}p, p0;

int t, pos;
const int INF =0x3f3f3f3f;
vector<point> v, s;

int cross(point a, point b, point c)
{
    return (b.x-a.x)*(c.y-a.y) - (c.x-a.x)*(b.y-a.y);
}
int dot(point a, point b, point c)
{
    return (c.x-a.x) * (b.x-a.x) + (c.y-a.y)*(b.y-a.y);
}
double dis(point a, point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)*1.0 + (a.y-b.y)*(a.y-b.y)*1.0);
}
int cmp(point a, point b)
{
    return (cross(p0, a, b) > 0 || ( cross(p0, a, b) == 0 && dis(p0, a) <= dis(p0, b) )) ? 1 : 0;
}
void graham()
{
    int m = 1;
    for (int i=2; i<v.size(); ++i)
    {
        while ( cross(s[m-1], s[m], v[i] ) < 0 )
        {
            s.pop_back();
            m--;
        }
        s.push_back( v[i] );
        m++;
    }
}
int onSegment(point a, point b, point c)
{
    // cross = 0 means a, b, c are aligned - 1.
    // 0 <= dot <= dist(ab) on the segment - 2.
    return ( cross(a, b, c) == 0 && dot(a, b, c) >= 0 && dot(a, b, c) <= dot(a, b, b)) ? 1 : 0;
}
int rayCrossing(point c)
{
    int i, j = v.size() - 1;
    int x = c.x, y = c.y;
    for (i=0; i < v.size(); ++i)
    {
        point a = s[i], b = s[j];
        if (onSegment(a, b, c))
        {
            cout << "inside" << endl;
            return 1;
        }
        if ( ((a.y < y && b.y >= y) 
                || (b.y < y && a.y >= y) )
                && (a.x <= x || b.x <= x))
            if (a.x+(y-a.i))
    }
    return odd;
}

int main()
{
    ios::sync_with_stdio(false), cin.tie(nullptr);

    while ( cin >> t )
    {
        // first set
        p0 = { INF, INF };
        pos = 0;
        for (int i=0; i<t; ++i)
        {
            cin >> p.x >> p.y;
            v.push_back(p);
            if ( p.y < p0.y || ( p.y == p0.y && p.x < p0.x) )
            {
                p0 = p;
                pos = i;
            }
        }

        point tmp;
        tmp = v[pos];
        v[pos] = v[0];
        v[0] = tmp;
        sort(v.begin()+1, v.end(), cmp);

        s.push_back(p0), s.push_back(v[1]);

        graham();

        // second set
        cin >> t;
        while ( t-- )
        {
            cin >> p.x >> p.y;
            if ( rayCrossing(p) )
                cout << "inside" << endl;
            else
                cout << "outside" << endl;
        }
    }
    return 0;
}
