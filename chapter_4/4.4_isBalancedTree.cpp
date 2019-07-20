/*
     given tree check if it balanced or not
*/
#include<iostream>
#include<queue>
#include<cmath>
using namespace std;

struct TreeNode{
     int data;
     TreeNode *left;
     TreeNode *right;

     TreeNode(int data){
          this->data = data;
          this->left = NULL;
          this->right = NULL;
     }
};

TreeNode *insert(){
     std::cout << "enter root of tree : ";
     int data;
     cin >> data;
     TreeNode *root = new TreeNode(data);
     queue<TreeNode *> q;
     q.push(root);
     while(!q.empty()){
          TreeNode *node = q.front();
          q.pop();
          std::cout << "enter left child of " << node->data << " : ";
          int leftData;
          cin >> leftData;

          std::cout << "enter right child of " << node->data << " : ";
          int rightData;
          cin >> rightData;

          if(leftData != 0){
               node->left = new TreeNode(leftData);
               q.push(node->left);
          }

          if(rightData != 0){
               node->right = new TreeNode(rightData);
               q.push(node->right);
          }
     }
     return root;
}

void display(TreeNode *root){
     if(!root)
          return;

     queue<TreeNode *> q;
     q.push(root);
     while(!q.empty()){
          TreeNode *node = q.front();
          q.pop();
          std::cout << node->data << " : ";

          if(node->left){
               std::cout << node->left->data << ' ';
               q.push(node->left);
          }

          if(node->right){
               std::cout << node->right->data;
               q.push(node->right);
          }
          std::cout << '\n';
     }
}

int height(TreeNode *root){
     if(!root)
          return 0;
     int left = height(root->left);
     int right = height(root->right);
     return (left > right ? left : right)+1;
}

// not good solution O(H*H) solution and O(H) space complexity
bool isBalanced(TreeNode *root){
     if(!root)
          return true;

     int left = height(root->left);
     int right = height(root->right);
     return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
}

struct result{
     int h;
     bool flag;
};

result isBalancedOptimal(TreeNode *root){
     if(!root){
          result ans;
          ans.h = 0;
          ans.flag = true;
          return ans;
     }

     result ansLeft = isBalancedOptimal(root->left);
     result ansRight = isBalancedOptimal(root->right);

     if(ansLeft.flag == false)
          return ansLeft;

     if(ansRight.flag == false)
          return ansRight;

     int leftHeight = ansLeft.h;
     int rightHeight = ansRight.h;
     bool flag = (abs(leftHeight - rightHeight) <= 1);
     result ans;
     ans.h = (leftHeight > rightHeight ? leftHeight : rightHeight)+1;
     ans.flag = ansLeft.flag && ansRight.flag && flag;
     return ans;
}

// most optimal
bool isBalancedMostOptimal(TreeNode *root){
     if(!root)
          return 0;

     int left = isBalancedMostOptimal(root->left);
     if(left == -1)
          return -1;

     int right = isBalancedMostOptimal(root->right);
     if(right == -1)
          return -1;

     int diff = abs(left - right);
     if(diff > 1){
          std::cout << root->data << " violation" << '\n';
          return -1;
     }

     else{
          std::cout << left << " " << right << " " << root->data << " " << (left > right ? left : right) + 1 << " " <<  "this" << '\n';
          return (left > right ? left : right) + 1;
     }
}

int main(){
     TreeNode *root = insert();
     display(root);
     std::cout << isBalanced(root) << '\n';
     result ans = isBalancedOptimal(root);
     std::cout << ans.flag << '\n';
     std::cout << isBalancedMostOptimal(root) << '\n';
}
