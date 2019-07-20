/*
     given two list have number in reverse order return third list which contains sum of both lists
*/

#include<iostream>
using namespace std;

class Node{
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
          while(head){
               std::cout << head->data << ' ';
               head  = head->next;
          }
          std::cout << '\n';
     }

public:
     LinkedList(){
          head = NULL;
     }

     void insert(int data){
          head = insert(head,data);
     }

     void display(){
          display(head);
     }

     LinkedList* operator+(LinkedList &list){
          if(!list.head)
               return this;

          if(!this->head)
               return &list;

          Node *ptr1 = head;
          Node *ptr2 = list.head;
          LinkedList *newhead = new LinkedList();
          int carry = 0;

          while(ptr1 && ptr2){
               int ans = ptr1->data + ptr2->data + carry;
               newhead->insert(ans%10);
               carry = ans/10;
               ptr1 = ptr1->next;
               ptr2 = ptr2->next;
          }

          while(ptr1){
               int ans = ptr1->data + carry;
               newhead->insert(ans%10);
               carry = ans/10;
               ptr1 = ptr1->next;
          }

          while(ptr2){
               int ans = ptr2->data + carry;
               newhead->insert(ans%10);
               carry = ans/10;
               ptr2 = ptr2->next;
          }

          if(carry)
               newhead->insert(carry);
          return newhead;
     }
};

int main(){

     LinkedList *head1 = new LinkedList();
     LinkedList *head2 = new LinkedList();

     while(true){
          int element;
          cin >> element;
          if(element == -1)
               break;
          head1->insert(element);
     }

     while(true){
          int element;
          cin >> element;
          if(element == -1)
               break;
          head2->insert(element);
     }

     LinkedList *head3 = (*head1) + (*head2);
     head3->display();
}
