#include<iostream>
#include<queue>
using namespace std;


class Node 
{
    public :
    int data;
    Node* left;
    Node* right;

    Node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;

    }
};

void inorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    inorder(root->left);
    cout << root-> data << " ";
    inorder(root->right);

}

void preorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    cout << root-> data << " ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(Node* root) {
    //base case
    if(root == NULL) {
        return ;
    }

    postorder(root->left);
    postorder(root->right);
    cout << root-> data << " ";

}

void levelOrderTraversal(Node* root) {
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* temp = q.front();
        q.pop();

        if(temp == NULL) { 
            //purana level complete traverse ho chuka hai
            cout << endl;
            if(!q.empty()) { 
                //queue still has some child ndoes
                q.push(NULL);
            }  
        }
        else{
            cout << temp -> data << " ";
            if(temp ->left) {
                q.push(temp ->left);
            }

            if(temp ->right) {
                q.push(temp ->right);
            }
        }
    }

}


Node* insertIntoBST(Node* root , int d)
{
    // base case 
    if (root == NULL)
    {
        root = new Node(d);
        return root;
    }

    if(d > root -> data)
    {
        // right part me insert karna ha 
        root->right = insertIntoBST(root->right , d); 
    }
    else
    {
        // left part me insert karna ha 
        root->left = insertIntoBST(root->left , d);
    }

    return root;
}

Node* minVal(Node* root)
{
    Node* temp = root;

    while (temp->left != NULL)
    {
        temp = temp->left;
    }
    return temp;
}

Node* maxVal(Node* root)
{
    Node* temp = root;

    while (temp->right != NULL)
    {
        temp = temp->right;
    }
    return temp;
}



void takeInput(Node* &root)
{
    int data;
    cin>>data;

    while (data != -1)
    {
       root = insertIntoBST(root , data);
        cin>>data;
    }
}



int main()
{
    Node* root = NULL;

    cout<<"enter data to create BST "<< endl;

    takeInput(root);

    cout<<"Printing the BST "<<endl;
    levelOrderTraversal(root);

    cout<< endl <<"Printing inorder "<< endl;
    inorder(root);

    cout<< endl <<"Printing Preorder "<< endl;
    preorder(root);

    cout<< endl <<"Printing Postorder "<< endl;
    postorder(root);

    cout<<endl;
    cout<<endl;
    
    cout<<"Min value is "<< minVal(root)->data <<endl;

    cout<<"Max value is "<< maxVal(root)->data <<endl;

    return 0;
}