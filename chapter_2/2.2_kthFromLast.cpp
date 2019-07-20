/*
     return kth node from last
*/

#include<iostream>
using namespace std;

class Node {
public:
     int data;
     Node *next;

     Node(int data){
          this->data = data;
          this->next = NULL;
     }
};

class LinkedList{
     Node *head;
     Node *insert(Node *head, int data){
          Node *node = new Node(data);
          if(!head)
               return node;
          Node *ptr = head;
          while(ptr->next)
               ptr = ptr->next;
          ptr->next = node;
          return head;
     }

     void display(Node *head){
          if(!head)
               return;
          Node *ptr = head;
          while(ptr){
               std::cout << ptr->data << ' ';
               ptr = ptr->next;
          }
          std::cout << '\n';
     }

     Node *kthNode(Node *head, int k){
          if(!head)
               return head;

          if(!head->next && k > 1)
               return NULL;

          Node *ptr = head;

          while(ptr && k-- >= 1)
               ptr = ptr->next;

          if(!ptr && k == -1)
               return head;

          if(!ptr || k > 0)
               return NULL;

          Node *node = head;
          while(ptr){
               ptr = ptr->next;
               node = node->next;
          }
          return node;
     }

public:
     LinkedList(){
          head = NULL;
     }

     void insert(int data){
          this->head = insert(this->head,data);
     }

     void display(){
          display(this->head);
     }

     Node *kthNode(int k){
          return kthNode(head,k);
     }
};

int main(){
     LinkedList *head = new LinkedList();
     while(true){
          int element;
          cin >> element;
          if(element == -1)
               break;
          head->insert(element);
     }
     head->display();
     while(true){
          int element;
          cin >> element;
          if(element == -1)
               return 0;
          Node *node = head->kthNode(element);
          if(node)
               std::cout << node->data << '\n';
          else
               std::cout << "naahh|" << '\n';
     }

}
