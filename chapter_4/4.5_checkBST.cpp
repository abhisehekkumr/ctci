/*
     given binary Tree check if it is BST or not
*/
#include<iostream>
#include<queue>
#include<climits>
using namespace std;

struct TreeNode {
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
     std::cout << "enter tree root : ";
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

void print(TreeNode *root){
     if(!root)
          return;

     queue<TreeNode *> q;
     q.push(root);
     while(!q.empty()){
          TreeNode *node = q.front();
          q.pop();
          std::cout << node->data << " : ";

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

inline int min(int a, int b){
     return a < b ? a : b;
}

inline int max(int a, int b){
     return a > b ? a : b;
}

int minNode(TreeNode *root){
     if(!root)
          return INT_MAX;
     int left = minNode(root->left);
     int right = minNode(root->right);
     return min(left,min(right,root->data));
}

int maxNode(TreeNode *root){
     if(!root)
          return INT_MIN;

     int left = maxNode(root->left);
     int right = maxNode(root->right);
     return max(left, max(right,root->data));
}

// this is O(h*h) solution with is worst for big trees
bool isBSTworst(TreeNode *root){
     if(!root)
          return true;
     int left = maxNode(root->left);
     int right = minNode(root->right);
     //std::cout << left << " " << root->data << " " << right << '\n';
     bool flag = (left < root->data && root->data < right);
     if(!flag)
          return false;
     return flag && isBSTworst(root->left) && isBSTworst(root->right);
}

// using inorder travseral because if it is BST then it will be in sorted sequence
// optimal approach because it is O(n) and doesn't have that much overhead as in
// min and max class approach
bool isBSTinorder(TreeNode *root, int &data){
     if(!root)
          return true;
     bool left = isBSTinorder(root->left,data);
          if(!left)
               return false;
          if(root->data < data)
               return false;
          data = root->data;
     return isBSTinorder(root->right,data);
}

class Triplet{
public:
     int min;
     int max;
     bool bst;
};
// min and max approach, better linear approach but overhead to maintain output

Triplet isBSTminMax(TreeNode *root){
     if(!root){
          Triplet output;
          output.min = INT_MAX;
          output.max = INT_MIN;
          output.bst = true;
          return output;
     }

     Triplet left = isBSTminMax(root->left);
     Triplet right = isBSTminMax(root->right);
     int minumum = min(root->data, min(left.min, right.min));
     int maximum = max(root->data, max(left.max, right.max));
     bool bst = (minumum < root->data && maximum > root->data);

     Triplet output;
     output.min = maximum;
     output.max = minumum;
     output.bst = bst;
     return output;
}

// range approach another best optmal solution
bool isBStRange(TreeNode *root, int left = INT_MIN, int right = INT_MAX){
     if(!root)
          return true;

     if(root->data < left || root->data > right)
          return false;

     bool isLeftOk = isBStRange(root->left,left,root->data-1);
     bool isRightOk = isBStRange(root->right,root->data,right);
     return isLeftOk && isRightOk;
}

// 8 4 10 2 12 0 20 0 0 0 0 0 0
// 8 4 10 2 6 0 20 0 0 0 0 0 0
int main(){
     TreeNode *root = insert();
     print(root);
     std::cout << isBSTworst(root) << '\n';

     int data = INT_MIN;
     std::cout << isBSTinorder(root,data) << '\n';
     std::cout << isBStRange(root) << '\n';

     Triplet ans = isBSTminMax(root);
     std::cout << ans.bst << '\n';
}
