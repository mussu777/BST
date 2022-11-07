#include <bits/stdc++.h> 
using namespace std;


    template <typename T >

    class Node
    {
    public :
        int data;
        Node<int> *left;
        Node<int> *right;

        Node(int data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~Node() {
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


pair<int,int> predecessorSuccessor(Node<int>* root, int key)
{
//    FIND KEY 
   Node<int>* temp = root ; 
   int pred = -1  ;
   int succ = -1 ; 
   
   
   while  (temp -> data != key)  
   {
       if ( temp -> data  > key )
       {
           succ = temp -> data ;             
           temp = temp -> left ; 
       }  
       else {
           pred = temp -> data ;            
           temp = temp -> right ;             
       }
   }
   
//      FINDING PRED AND SUCC 
   
//     PRED 
   Node<int>* leftTree = temp -> left ;
   while  (leftTree !=  NULL) {
       pred = leftTree -> data ; 
       leftTree = leftTree -> right ; 
   }
    
//      SUCC
   Node<int>* rightTree = temp -> right ;
   while ( rightTree != NULL ) {
       succ = rightTree -> data ;
       rightTree = rightTree -> left ; 
   }
   
   pair<int,int> ans = make_pair(pred , succ) ;
   return ans ; 
}

