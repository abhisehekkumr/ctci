/*
     implementing binary seach tree
*/

#include<iostream>
using namespace std;

template <typename T>
class TreeNode{
public:
     T data;
     TreeNode *left;
     TreeNode *right;

     TreeNode(T data){
          this->data = data;
          this->left = NULL;
          this->right = NULL;
     }
};

template <typename T>
class BST{

     TreeNode<T> *root;

     TreeNode<T> *insert(TreeNode<T> *root, T data){
          if(!root)
               return new TreeNode<T>(data);
          if(root->data > data)
               root->left = insert(root->left,data);
          else if(root->data < data)
               root->right = insert(root->right,data);
          return root;
     }

     bool find(TreeNode<T> *root, T data){
          if(!root)
               return false;
          if(root->data == data)
               return true;
          if(find(root->left,data))
               return true;
          return find(root->right,data);
     }

     T inorder(TreeNode<T> *root){
          if(!root)
               return 0;

          if(root->left == NULL)
               return root->data;
          return inorder(root->left);
     }

     TreeNode<T> *remove(TreeNode<T> *root, T data){
          if(!root)
               return root;
          if(root->data > data)
               root->left = remove(root->left,data);
          else if(root->data < data)
               root->right = remove(root->right,data);
          else{

               if(!root->left)
                    return root->right;

               if(!root->right)
                    return root->left;

               T val = inorder(root->right);
               root->data = val;
               root->right = remove(root->right,val);
          }
          return root;
     }

public:
     BST(){
          root = NULL;
     }

     void insert(T data){
          root = insert(root,data);
     }

     void remove(T data){
          root = remove(root,data);
     }

     bool fidn(T data){
          return find(root,data);
     }
};

int main(){
     BST<int> *tree = new BST<int>();
     while(true){
          int data;
          cin >> data;
          if(data == -1)
               break;
          tree->insert(data);
     }

     std::cout << tree->fidn(10) << '\n';
     std::cout << tree->fidn(1) << '\n';

     tree->remove(10);
     tree->remove(1);

     std::cout << tree->fidn(10) << '\n';
     std::cout << tree->fiS(1) << '\n';
}
