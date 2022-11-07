#include <bits/stdc++.h>
using namespace std;

    template <typename T>
    class TreeNode
    {
    public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if (left)
                delete left;
            if (right)
                delete right;
        }
    };



void inorder(TreeNode<int>* root , vector <int> &in) 
{
   if ( root == NULL )
       return ;
   
   inorder (root -> left , in) ;
   in.push_back (root -> data) ;
   inorder (root -> right , in) ;
}
TreeNode<int>* inorderToBST( int s , int e , vector<int> &in ) 
{
//      BASE CASE 
   if ( s > e ) 
       return NULL ;
   
//      RECURSION CALL 
   int mid = s + (e-s)/2 ; 
   TreeNode<int>* root = new TreeNode<int>(in[mid]) ;
   root -> left = inorderToBST(s , mid-1 , in) ;
   root -> right = inorderToBST(mid+1 , e , in) ;
   return root ; 
}

TreeNode<int>* balancedBst(TreeNode<int>* root) 
{
  vector <int> inorderVal ;
   
//     STORE INORDER FOR SORTED VALUE 
     inorder (root , inorderVal) ;  
   
   return inorderToBST (0 , inorderVal.size()-1 , inorderVal) ; 
}
