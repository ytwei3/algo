// 52 - Hanging Nests
//
// find the most unblanced node in a
// Binary Search Tree
#include <stdio.h>
#include <algorithm>

int t, n, s, h, res;

struct Node
{
    int spot, depth;
    struct Node *small;
    struct Node *large;

    Node(int v);
};
Node::Node(int v) : 
    spot(v),
    depth(0),
    small(nullptr),
    large(nullptr)
{}
Node* insert(Node* r, int spot)
{
    if (r == nullptr )
        r = new Node(spot);
    else if ( spot <= r->spot )
        r->small = insert(r->small, spot);
    else
        r->large = insert(r->large, spot);
        
    return r;
}
void findDiff(Node* r)
{
    if ( r->small == nullptr && r->large == nullptr )
        return ;
    else
    {
            findDiff(r->large);
            findDiff(r->small);
    }

    if ( r->small != nullptr && r->large != nullptr )
    {
        int diff = std::abs(r->small->depth - r->large->depth);
        if ( diff >= res )
            res = r->spot;
        delete r->small;
        delete r->large;
        return ;
    }
    else if ( r->large == nullptr )
    {
        r->depth = r->small->depth + 1;
        delete r->small;
        return ;
    }
    else
    {
        r->depth = r->large->depth + 1;
        delete r->large;
        return ;
    }
}


int main ()
{
    scanf("%d", &t);
    for (int i=1; i<=t; ++i)
    {
        res = 0;
        Node* root = nullptr;
        scanf("%d", &n);
        while ( n-- )
        {
            scanf("%d", &s);
            insert(root, s);
        }
        findDiff(root);
        printf("Flock #%d: %d", i, res);
    }
    return 0;
}
