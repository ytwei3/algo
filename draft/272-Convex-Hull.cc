//
// 272 - Convex Hull
//
#include <stdio.h>
#include <vector>
#include <stack>
#include <unordered_map>

struct Crood
{
    double x, y;
};

int t, n, m;
const double INF = 0x3f3f3f3f;
double ar[100005];
Crood p[100005];
Crood p0;
std::vector<Crood> s;
std::vector<double> d;
std::unordered_map<double, int> map;

double isLeft(Crood a, Crood b, Crood c)
{
    double res = (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
    return res;
}
void sort(double reg[], int start, int end)
{
    if (start >= end)
        return ;
    int len = end - start, mid = (len >> 1) + start;
    int start1 = start, end1 = mid;
    int start2 = mid + 1, end2 = end;
    sort(reg, start1, end1);
    sort(reg, start2, end2);
    int k = start;
    while ( start1 <= end1 && start2 <= end2 )
        reg[k++] = d[start1] < d[start2] ? d[start1++] : d[start2++];
    while ( start1 <= end1 )
        reg[k++] = d[start1++];
    while ( start2 <= end2 )
        reg[k++] = d[start2++];
    for (k = start; k <= end; k++)
        d[k] = reg[k];
}

int main()
{
    while ( scanf("%d", &t) != -1 )
    {
        while ( t-- )
        {
            scanf("%d", &n);
            p0.x = p0.y = INF;
            for (int i=0; i<n; ++i)
            {
                scanf("%lf%lf", &p[i].x, &p[i].y);
                if ( p[i].y < p0.y || ( p[i].y == p0.y && p[i].x < p0.x ) )
                    p0 = p[i];
            }

            double tmp;
            for (int i=1; i<=n; ++i)
            {
                tmp = ( p[i].y - p0.y ) / ( p[i].x - p0.x );
                if ( !map.count(tmp) )
                {
                    d.push_back(tmp);
                    map[tmp] = i;
                }
                else if ( p[ map[tmp] ].x < p[i].x )
                    map[tmp] = i;
            }
            double reg[d.size()];
            sort(reg, 0, d.size()-1 );

            s.push_back( p[0] ), s.push_back( p[1] );

            m = 1;
            for ( int i=2; i<n; ++i )
            {
                while ( isLeft(s[m-1], s[m], p[i]) < 0 )
                {
                    s.pop_back();
                    m--;
                }
                s.push_back(p[i]);
                m++;
            }
        }
        printf("%d\n", m);
        while ( !s.empty() )
        {
            printf("%d %d\n", s.back().x, s.back().y );
            s.pop_back();
        }
    }
    return 0;
}
