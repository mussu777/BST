#include <bits/stdc++.h>
using namespace std;


template <typename T>
class Node
{
public:
    int data;
    Node<int> *left;
    Node<int> *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

void inorder(Node<int> *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

bool twoSumInBST(Node<int> *root, int target)
{
    vector<int> inorderVal;

    //      STORE INORDER --> SORTED VALUE
    inorder(root, inorderVal);
    
    //      USING 2 POINTER APPROACH TO CHECK IF PAIR EXISTS
    int i = 0, j = inorderVal.size() - 1;

    while (i < j)
    {
        int sum = inorderVal[i] + inorderVal[j];

        if (sum == target)
        {
            return true;
        }
        else if (sum > target)
        {
            j--;
        }
        else
        {
            i++;
        }
    }

    return false;
}