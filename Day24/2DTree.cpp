/* 
The 2d tree is a modification to the BST that allows for efficient 
processing of multi-dimensional search keys. The 2d tree differs 
from the BST in that each level of the 2d tree makes branching 
decisions based on a particular search key associated with that 
level, called the discriminator. We define the discriminator at 
level i to be (i mod 2) for 2 dimensions. 

The x-coordinate field arbitrarily designated key 0, and the 
y-coordinate field designated key 1. At each level, the discriminator
alternates between x and y. Thus, a node N at level 0 (the root) would
have in its left subtree only nodes whose x values are less than Nx. 
The right subtree would contain nodes whose x values are greater than 
Nx. A node M at level 1 would have in its left subtree only nodes whose
y values are less than My. There is no restriction on the relative values 
of Mx and the x values of M ‘s descendants, because branching decisions 
made at M are based solely on the y coordinate.

Write a program to insert an elements into the 2d-tree 
and print elements in inorder traversal.

0 <= n < 50
0 <= x,y <=105

*/

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int element[2];
    Node *left, *right;
};

struct Node* newNode(int arr[])
{
    struct Node* temp = new Node;
    temp->element[0] = arr[0];
    temp->element[1] = arr[1];
    temp->left = temp->right = NULL;
    return temp;
}

Node *insertElement(Node *root, int element[], int level)
{
    if (root == NULL)
       return newNode(element);
    int current_level = level % 2;
    if (element[current_level] < (root->element[current_level]))
        root->left  = insertElement(root->left, element, level + 1);
    else
        root->right = insertElement(root->right, element, level + 1);
    return root;
}

Node* insert(Node *root, int element[])
{
    return insertElement(root, element, 0);
}

void inorder(Node *root)
{
    if(root!= NULL)
    {
        inorder(root->left);
        cout << "(" << root->element[0] << "," << root->element[1] << ") ";
        inorder(root->right);
    }
}

int main()
{
    struct Node *root = NULL;
    int elements[][2] = {{40,45}, {15,70}, {70,10}, {69,50},{66,85}, {85,90}};
    int n = sizeof(elements)/sizeof(elements[0]);
    for(int i = 0; i<n; i++)
        root = insert(root, elements[i]);
    inorder(root);
    return 0;
}