#include <bits/stdc++.h> 
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



int solve ( Node* root, int& i , int k  ) 
{
//      BASE CASE 
   if (root == NULL) {
       return -1 ; 
   }
   
//      RECURSIVE CALL 
   
//       HERE WE ARE AT L  ACC. TO LNR    
   int left = solve ( root -> left , i , k ) ;
   if (left != -1) 
   {
       return left ; 
   }
   
//       NOW AT N 
   i++ ;
   if ( i == k ) 
       return root -> data ; 
   
//      AT R 
   return solve ( root -> right , i , k ) ;
}

int kthSmallest(Node* root, int k  ) 
{
   int i = 0 ; 
  int ans = solve ( root , i , k ) ; 
   return ans ; 
}