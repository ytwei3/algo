// C++ program to construct a linked
// list from 2D matrix | Iterative Approach
#include <bits/stdc++.h>
using namespace std;

// struct node of linked list
struct node
{
	int data;
	node *right, *down;
};

// utility function to create a new node with given data
node* newNode(int d)
{
	node* temp = new node;
	temp->data = d;
	temp->right = temp->down = NULL;
	return temp;
}

// utility function to print the linked list pointed to by head pointer
void display(node* head)
{
	node *rp, *dp = head;

	// loop until the down pointer is not NULL
	while (dp) {
		rp = dp;

		// loop until the right pointer is not NULL
		while (rp) {
			cout << rp->data << " ";
			rp = rp->right;
		}
		cout << endl;
		dp = dp->down;
	}
}

// function which constructs the linked list
// from the given matrix of size m * n
// and returns the head pointer of the linked list
node* constructLinkedMatrix(int mat[][3], int m, int n)
{
	// stores the head of the linked list
	node* mainhead = NULL;

	// stores the head of linked lists of each row
	node* head[m];
	node *righttemp, *newptr;

	// Firstly, we create m linked lists
	// by setting all the right nodes of every row
	for (int i = 0; i < m; i++) {

		// initially set the head of ith row as NULL
		head[i] = NULL;
		for (int j = 0; j < n; j++) {
			newptr = newNode(mat[i][j]);

			// stores the mat[0][0] node as
			// the mainhead of the linked list
			if (!mainhead)
				mainhead = newptr;

			if (!head[i])
				head[i] = newptr;
			else
				righttemp->right = newptr;

			righttemp = newptr;
		}
	}

	// Then, for every ith and (i+1)th list,
	// we set the down pointers of
	// every node of ith list
	// with its corresponding
	// node of (i+1)th list
	for (int i = 0; i < m - 1; i++) {

		node *temp1 = head[i], *temp2 = head[i + 1];

		while (temp1 && temp2) {

			temp1->down = temp2;
			temp1 = temp1->right;
			temp2 = temp2->right;
		}
	}

	// return the mainhead pointer of the linked list
	return mainhead;
}

// Driver program to test the above function
int main()
{
	int m, n; // m = rows and n = columns
	m = 3, n = 3;
	// 2D matrix
	int mat[][3] = { { 1, 2, 3 },
					{ 4, 5, 6 },
					{ 7, 8, 9 } };

	node* head = constructLinkedMatrix(mat, m, n);
	display(head);

	return 0;
}

