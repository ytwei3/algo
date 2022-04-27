//
/* 863 - Stern-Brocot Tree */
//
#include <cstdio>
using namespace std;

struct node
{
    int u, v;
    double val();
};
double node::val()
{
    return 1.0*u/v;
}

int main()
{
    node a, b, ra, la, rb, lb, fa, fb, father;
    while ( ~scanf("%d%d%d%d", &a.u, &a.v, &b.u, &b.v)
                && (a.u || b.u || a.v || b.v) )
    {
        ra = rb = { 1, 0 }, la = lb = { 0, 1 };
        fa = fb = {1, 1};

        int p = 0;
        while ( fa.u == fb.u && fa.v == fb.v )
        {
            father = fa;

            if ( (a.u == fa.u && a.v == fa.v) ||
                    (b.u == fb.u && b.v == fb.v) )
            {
                if ( a.u == b.u && a.v == b.v )
                {
                    p = printf("%d %d\n", a.u, a.v);
                    break;
                }
                else
                {
                    p = printf("%d %d\n", fa.u, fa.v);
                    break;
                }
            }

            // a part
            if ( a.val() > fa.val() )
                la = fa, fa = { ra.u + fa.u, ra.v + fa.v };
            else
                ra = fa, fa = { la.u + fa.u, la.v + fa.v };

            // b part
            if ( b.val() > fb.val() )
                lb = fb, fb = { rb.u + fb.u, rb.v + fb.v };
            else
                rb = fb, fb = { lb.u + fb.u, lb.v + fb.v };
        }

        if ( !p )
            printf("%d %d\n", father.u, father.v);
    }
    return 0;
}
