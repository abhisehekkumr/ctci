/*
     given two binary tree determine if one is sub tree of another
*/

#include<iostream>
#include<queue>
#include<sstream>
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
     std::cout << "enter root : ";
     int data;
     cin >> data;
     TreeNode *root = new TreeNode(data);
     queue<TreeNode *> q;
     q.push(root);

     while(!q.empty()){
          TreeNode *node = q.front();
          q.pop();
          std::cout << "enter left child of " << node->data << " :  ";
          int leftData;
          cin >> leftData;

          std::cout << "enter right child of " << node->data << " :  ";
          int rightData;
          cin >> rightData;

          if(leftData){
               node->left = new TreeNode(leftData);
               q.push(node->left);
          }

          if(rightData){
               node->right = new TreeNode(rightData);
               q.push(node->right);
          }
     }
     return root;
}

void printTree(TreeNode *root){
     if(!root)
          return;

     queue<TreeNode *> q;
     q.push(root);

     while(!q.empty()){
          TreeNode *node = q.front();
          q.pop();

          std::cout << node->data <<  " : ";
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

string getStringTree(TreeNode *root){
     if(!root){
          return "X";
     }
     ostringstream convert;
     convert << root->data;
     string ans = convert.str();

     ans += getStringTree(root->left);
     ans += getStringTree(root->right);
     return ans;
}


// space complexity O(n + m) and time complexity O(n)
// for string matching
bool isSubTree(TreeNode *firstTree, TreeNode *secondTree){
     if(!firstTree || !secondTree)
          return false;

     string first = getStringTree(firstTree);
     string second = getStringTree(secondTree);
     //std::cout << first << '\n';
     //std::cout << second << '\n';
     return first.find(second) != std :: string :: npos;
}

bool find(TreeNode *firstTree, TreeNode *secondTree){
     if(!firstTree && !secondTree)
          return true;
     if(!firstTree || !secondTree)
          return false;
     if(firstTree->data != secondTree->data)
          return false;
     return find(firstTree->left,secondTree->left) && find(firstTree->right, secondTree->right);
}


// worst case time complexity is O(n + k*m) where k is total possible root maches
// but its complexity can also becomes O(n*m) and space complexity is O(log n
)
bool isSubTreeOptimal(TreeNode *firstTree, TreeNode *secondTree){
     if(!firstTree || !secondTree)
          return false;
     if(firstTree->data == secondTree->data){
          if(find(firstTree,secondTree))
               return true;
     }
     bool left = isSubTreeOptimal(firstTree->left,secondTree);
     if(left)
          return true;
     return isSubTreeOptimal(firstTree->right,secondTree);
}

int main(){
     TreeNode *firstTree = insert();
     TreeNode *secondTree = insert();
     std::cout << isSubTree(firstTree,secondTree) << '\n';
     std::cout << isSubTreeOptimal(firstTree,secondTree) << '\n';
}
