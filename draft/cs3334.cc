#include <cstdio>

int mx; // the mx value 

struct Tree
{
    int data;
    Tree *left, *right;
    int MaxInternal();
};
int Tree::MaxInternal()
{
}

// q1 
struct List
{
    int data;
    List *nx; // next
};

void OutputCommon(List *a, List *b, List *c)
{
    // assume the size of number is 1000
    int ar[1001];
    for (int i=0; i<1001; i++)
        ar[i] = 0;

    while ( a != nullptr )
    {
        ar[a->data]++;
        a = a->nx;
    }

    while ( b != nullptr )
    {
        ar[b->data]++;
        b = b->nx;
    }

    while ( c != nullptr )
    {
        // if ar is 2(a & b yes), output directly
        if ( ar[c->data] == 2 )
            printf("%d ", &ar[c->data]);
        c = c->nx;
    }
}

int main ()
{
    // first, assume i use adjency list
    // to store my tree, node.

    return 0;
}
