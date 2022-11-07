#include <iostream>
#include <queue>
using namespace std;


    class Node 
    {
    public : 
        int data;
        Node *left;
        Node *right;

        Node(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };


bool isBst(Node *root, int min, int max){
    //base case 
    if(root==NULL)
        return true;
    if(root->data >= min && root->data <= max)
    {
        
        bool left = isBst(root->left , min , root->data);
        bool right = isBst(root->right , root->data , max);
        return left && right;
    }
    else
        return false;
     }
bool validateBST(Node *root) {
    // Write your code here
   
    return isBst(root,INT32_MIN , INT32_MAX);
}





