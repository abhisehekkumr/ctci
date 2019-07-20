/*
     given sorted array create BST with minumum height
*/
#include<iostream>
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

void display(TreeNode *root){
     if(!root)
          return;
     display(root->left);
     std::cout << root->data << ' ';
     display(root->right);
}

int height(TreeNode *root){
     if(!root)
          return 0;
     int left = height(root->left);
     int right = height(root->right);
     return (left > right ? left : right)+1;
}

TreeNode *buildTree(int arr[], int low, int end){
     if(low > end)
          return NULL;
     int mid = (low + end)/2;
     TreeNode *root = new TreeNode(arr[mid]);
     root->left = buildTree(arr,low,mid-1);
     root->right = buildTree(arr,mid+1,end);
     return root;
}

int main(){
     int n;
     cin >> n;

     int arr[n];
     for(int i = 0; i < n; i++)
          cin >> arr[i];
     TreeNode *root = buildTree(arr,0,n-1);
     display(root);
     std::cout << '\n';
     std::cout << height(root) << '\n';
}
