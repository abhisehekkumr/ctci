/*
     given BST convert it into a Linked list
*/
#include<iostream>
using namespace std;

struct Binode{
     int data;
     Binode *node1;
     Binode *node2;

     Binode(int data){
          this->data = data;
          this->node1 = NULL;
          this->node2 = NULL;
     }
};

Binode *insert(Binode *root, int data){
     if(!root)
          return new Binode(data);
     if(root->data > data)
          root->node1 = insert(root->node1,data);
     else if(root->data < data)
          root->node2 = insert(root->node2,data);
     return root;
}

void display(Binode *root){
     if(!root)
          return;
     display(root->node1);
     std::cout << root->data << ' ';
     display(root->node2);
}

struct list{
     Binode *head;
     Binode *ptr;

     list(){
          head = NULL;
          ptr = NULL;
     }
};

void BSTtoLinkedList(Binode *root, list *node){
     if(!root){
          return;
     }

     Binode *node2 = root->node2;
     Binode *node1 = root->node1;

     BSTtoLinkedList(root->node1,node);
     // root is head of the linked list
     if((node)->head == NULL){
          root->node1 = NULL;
          root->node2 = NULL;
          (node)->head = root;
          (node)->ptr = root;
          return;
     }

     else{
          root->node1 = (node)->ptr;
          (node)->ptr->node2 = root;
          (node)->ptr = root;
     }
     //std::cout << root->data << '\n';
     if(node2)
          BSTtoLinkedList(node2,node);
}

int main(){
     Binode *root = NULL;
     while(true){
          int data;
          cin >> data;
          if(data == -1)
               break;
          root = insert(root,data);
     }
     std::cout << "tree output : ";
     display(root);
     std::cout << '\n';

     list *node = new list();
     BSTtoLinkedList(root, node);
     Binode *head = node->head;
     Binode *prev = NULL;
     std::cout << "linked list : ";
     while(head){
          prev = head;
          std::cout << head->data << ' ';
          head = head->node2;
     }
     std::cout << '\n';
     std::cout << "traversing reverse : ";
     while(prev){
          std::cout << prev->data << ' ';
          prev = prev->node1;
     }
     std::cout << '\n';
}
/*
9 8 7 6 5 4 3 2 1 -1
4 2 5 1 3 6 0 -1
*/
