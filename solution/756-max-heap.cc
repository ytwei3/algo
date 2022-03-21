// 756 - Max Heap
//
//
#include <stdio.h>

int mh[100001]; // max-heap

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;

    return ;
}
void check(int pos)
{
    int child = pos;
    int parent = child/2;

    if ( mh[parent] >= mh[child] )
        return ;
    else
    {
        swap(&mh[child], &mh[parent]);
        check(parent);
    }
}
void insert(int *s)
{
    int k;
    scanf("%d", &k);
    mh[*s] = k;

    check(*s);
    *s = *s + 1;

    return ;
}
void pop(int i)
{
    if ( mh[i] >= mh[2*i] && mh[i] >= mh[2*i+1] )
        return ;

    int child;
    if ( mh[2*i] > mh[2*i+1] )
        child = 2*i;
    else
        child = 2*i+1;

    swap(&mh[i], &mh[child]);
    pop(child);
}

int main()
{
    mh[0] = 1001; // 1 <= k <= 1000

    int n;
    while ( scanf("%d", &n) != EOF )
    {
        for (int i=1; i<100001; ++i)
            mh[i] = 0;

        char op;
        int size = 1;
        for (int i=0; i<n; ++i)
        {
            scanf(" %c", &op);

            if ( op == 'a')
                insert(&size);
            else if ( op == 'p')
            {
                size = size - 1;
                mh[1] = mh[size];
                mh[size] = 0;

                pop(1);
            }
            else if ( op == 'r')
            {
                long long sum = 0;
                for (int i=1; i<size; ++i)
                    sum += mh[i];

                printf("%lld\n", sum);
            }
        }
    }
    return 0;
}
