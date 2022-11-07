#include <bits/stdc++.h>
using namespace std;

// PROCESSSS 1.

template <typename T>
class TreeNode
{

public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }
    }
};

void inorder(TreeNode<int> *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());

    int i = 0, j = 0;
    int k = 0;

    while (i < a.size() && j < b.size())
    {
        if (a[i] < b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }

    while (i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }
    while (j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }
    return ans;
}

TreeNode<int> *inorderToBST(int s, int e, vector<int> &in)
{
    //      BASE CASE
    if (s > e)
        return NULL;

    //      RECURSION CALL
    int mid = s + (e - s) / 2;
    TreeNode<int> *root = new TreeNode<int>(in[mid]);
    root->left = inorderToBST(s, mid - 1, in);
    root->right = inorderToBST(mid + 1, e, in);
    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    //     STEP-1 --> STORE INORDER
    vector<int> bst1, bst2;
    inorder(root1, bst1);
    inorder(root2, bst2);

    //      STEP-2 --> MERGE BOTH SORTED ARRAYS
    vector<int> mergeArray = mergeArrays(bst1, bst2);

    //      STEP-3--> USE INORDER ARRAY TO BUILD BST
    int s = 0, e = mergeArray.size() - 1;
    return inorderToBST(s, e, mergeArray);
}

// PROCESS 2

// #include <bits/stdc++.h>
/*************************************************************

    Following is the Binary Tree node structure:

    class TreeNode{

        public :
            int data;
            TreeNode *left;
            TreeNode *right;

            TreeNode(int data) {
                this -> data = data;
                left = NULL;
                right = NULL;
            }

            ~TreeNode() {
            if (left){
            delete left;
            }

            if (right){
            delete right;
            }
        }
    };

*************************************************************/
void convertToDLL(TreeNode<int> *root, TreeNode<int> *&head)
{
    if (root == NULL)
        return;

    convertToDLL(root->right, head);

    root->right = head;
    if (head != NULL)
        head->left = root;
    head = root;

    convertToDLL(root->left, head);
}

TreeNode<int> *mergelinkedList(TreeNode<int> *head1, TreeNode<int> *head2)
{
    TreeNode<int> *head = NULL;
    TreeNode<int> *tail = NULL;

    while (head1 != NULL && head2 != NULL)
    {
        if (head1->data < head2->data)
        {
            if (head == NULL)
            {
                head = head1;
                tail = head1;
                head1 = head1->right;
            }
            else
            {
                tail->right = head1;
                head1->left = tail;
                tail = head1;
                head1 = head1->right;
            }
        }
        else
        {
            if (head == NULL)
            {
                head = head2;
                tail = head2;
                head2 = head2->right;
            }
            else
            {
                tail->right = head2;
                head2->left = tail;
                tail = head2;
                head2 = head2->right;
            }
        }
    }

    while (head1)
    {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2)
    {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

int countNodes(TreeNode<int> *head)
{
    int cnt = 0;
    TreeNode<int> *temp = head;
    while (temp != NULL)
    {
        cnt++;
        temp = temp->right;
    }

    return cnt;
}

TreeNode<int> *convertDLLtoBST(TreeNode<int> *&head, int n)
{
    // BASE CASE
    if (n <= 0 || head == NULL)
        return NULL;

    TreeNode<int> *leftTree = convertDLLtoBST(head, n / 2);

    TreeNode<int> *root = head;
    root->left = leftTree;
    head = head->right;

    root->right = convertDLLtoBST(head, n - n / 2 - 1);

    return root;
}

TreeNode<int> *mergeBST(TreeNode<int> *root1, TreeNode<int> *root2)
{
    TreeNode<int> *head1 = NULL, *head2 = NULL;
    convertToDLL(root1, head1);
    convertToDLL(root2, head2);

    TreeNode<int> *head = mergelinkedList(head1, head2);

    int n = countNodes(head);

    TreeNode<int> *ans = convertDLLtoBST(head, n);

    return ans;
}