//
/* 814 - Puzzle Game */
//
#include <cstdio>
using namespace std;

struct node
{
    int data;
    node* right, *down;
} board[1001][1001], *head;

int n, m, q;
int r1, r2, c1, c2, h, w;

void output()
{
    node *e = head, *f; 
    e = e->down;
    for (int i = 0; i < n; i++)
    {
        printf("%d", e->right->data);
        f = e->right;
        for (int j = 1; j < m; j++)
        {
            f = f->right; 
            printf(" %d", f->data);
        }
        puts("");
        e = e->down;
    }
}
void init()
{
    for (int i=1; i<=n; i++)
        for (int j=1; j<=n; j++)
            scanf("%d", &board[i][j].data);

    for (int i=0; i<=n; i++)
        for (int j=0; j<=m; j++)
        {
            board[i][j].down = &board[i+1][j];
            board[i][j].right = &board[i][j+1];
        }

    head = &board[0][0];
}
node* ad(node *a, int t)
{
    if ( t == 1 )
        return a;
    return ad(a->down, --t);
}
node* ar(node *a, int t)
{
    if ( t == 1 )
        return a;
    return ar(a->right, --t);
}
node* br(node *b, int t)
{
    if ( t == 1 )
        return b;
    return br(b->right, --t);
}
node* bd(node *b, int t)
{
    if ( t == 1 )
        return b;
    return bd(b->down, --t);
}

int main()
{
    while ( ~scanf("%d%d%d", &n, &m, &q) )
    {
        init();

        node *a, *b, *c, *d;
        while ( q-- )
        {
            a = b = head;
            scanf("%d%d%d%d%d%d", &r1, &c1, &r2, &c2, &h, &w);
            a = ar(ad(a, r1), c1);
            b = br(bd(b, r2), c2);

            c = a;
            d = b;

            for (int i=0; i<h; i++)
            {
                c = c-> down, d = d-> down;
                node * tmp = c->right;
                c->right = d->right;
                d->right = tmp;
            }

            for (int i=0; i<w; i++)
            {
                a = a-> right, b = b-> right;
                node *tmp = a->down;
                a->down = b->down;
                b->down = tmp;
            }

            for (int i=0; i<w; i++)
            {
                c = c-> right, d = d-> right;
                node *tmp = c->down;
                c->down = d->down;
                d->down = tmp;
            }

            for (int i=0; i<h; i++)
            {
                a = a -> down, b = b-> down;
                node * tmp = a->right;
                a->right = b->right;
                b->right = tmp;
            }
        }
        output();
    }
    return 0;
}
