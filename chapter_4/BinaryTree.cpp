/*
     implementing binary tree
*/

#include<iostream>
#include<queue>
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
class BinaryTree{
     TreeNode<T> *root;

     TreeNode<T> *insert(TreeNode<T> *root){
          std::cout << "enter root of tree" << " : ";
          T data;
          cin >> data;

          TreeNode<T> *node = new TreeNode<T>(data);
          root = node;
          queue<TreeNode<T> *> q;
          q.push(root);

          while(!q.empty()){
               TreeNode<T> *node = q.front();
               q.pop();

               std::cout << "enter left child of " << node->data << " : " << ' ';
               T leftData;
               cin >> leftData;

               std::cout << "enter right child of " << node->data << " : " << ' ';
               T rightData;
               cin >> rightData;

               if(leftData != 0){
                    node->left = new TreeNode<T>(leftData);
                    q.push(node->left);
               }
               if(rightData != 0){
                    node->right = new TreeNode<T>(rightData);
                    q.push(node->right);
               }
          }
          return root;
     }

     void print(TreeNode<T> *root){
          if(!root)
               return;

          queue<TreeNode<T> *> q;
          q.push(root);
          while(!q.empty()){
               TreeNode<T> *node = q.front();
               q.pop();

               std::cout << node->data << ':';
               if(node->left){
                    std::cout << node->left->data << " ";
                    q.push(node->left);
               }

               if(node->right){
                    std::cout << node->right->data << " ";
                    q.push(node->right);
               }
               std::cout << '\n';
          }
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

public:
     BinaryTree(){
          root = NULL;
     }

     void insert(){
          root = insert(root);
     }

     void print(){
          print(root);
     }

     bool find(T data){
          return find(root,data);
     }
};

int main(){
     BinaryTree<int> *tree = new BinaryTree<int>();
     tree->insert();
     tree->print();
     std::cout << tree->find(9) << '\n';
     std::cout << tree->find(11) << '\n';
}
