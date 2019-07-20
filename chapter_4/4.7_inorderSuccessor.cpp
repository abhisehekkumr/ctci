/*
     given node find it's inorder successor
     what if right child doesn't exit
*/
#include<iostream>
using namespace std;

struct TreeNode {
     int data;
     TreeNode *left;
     TreeNode *right;
     TreeNode *parent;

     TreeNode(int data){
          this->data = data;
          this->left = NULL;
          this->right = NULL;
          this->parent = NULL;
     }
};

TreeNode *insert(TreeNode *root, int data){
     if(!root)
          return new TreeNode(data);
     if(root->data > data){
          root->left = insert(root->left,data);
          root->left->parent = root;
     }
     else if(root->data < data){
          root->right = insert(root->right,data);
          root->right->parent = root;
     }
     return root;
}

void display(TreeNode *root){
     if(!root)
          return;
     display(root->left);
     std::cout << root->data << ' ';
     display(root->right);
}

TreeNode *leftMostChild(TreeNode *root){
     if(!root)
          return root;
     if(!root->left)
          return root;
     return leftMostChild(root->left);
}

TreeNode *node(TreeNode *root, int data){
     if(!root)
          return root;
     if(root->data == data)
          return root;
     else if(root->data > data)
          return node(root->left,data);
     return node(root->right,data);
}

// need to design function that wil give node
TreeNode *inorderSuccesor(TreeNode *root){
     if(!root)
          return root;
     if(root->right)
          return leftMostChild(root->right);
     TreeNode *q = root;
     TreeNode *x = q->parent;

     while(x && x->left != q){
          q = x;
          x = q->parent;
     }
     return x;
}

int main(){
     TreeNode *root = NULL;
     while(true){
          int data;
          cin >> data;
          if(data == 0)
               break;
          root = insert(root,data);
     }
     int data;
     cin >> data;
     TreeNode *n = node(root,data);
     n = inorderSuccesor(n);
     if(n)
          std::cout << n->data << '\n';
     else
          std::cout << "nothing" << '\n';
     // 5 4 3 2 1 0
     // 15 10 7 11 16 17 18 19 0
     // 15 10 7 11 16 0
     //display(root);
     //std::cout << '\n';
}
