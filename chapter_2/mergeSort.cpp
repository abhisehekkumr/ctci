#include<iostream>
using namespace std;

template<typename T>
struct Node {
     T data;
     Node *next;

     Node(T data){
          this->data = data;
          this->next = NULL;
     }
};

Node<int>* insert(Node<int> *head, int data){
     Node<int> *node = new Node<int>(data);
     if(!head)
          return node;

     Node<int> *ptr = head;
     while(ptr->next)
          ptr = ptr->next;
     ptr->next = node;
     return head;
}

Node<int>* DivideList(Node<int> *head){
     if(!head || !head->next)
          return head;

     Node<int> *slow = head;
     Node<int> *fast = head->next;

     while(fast && fast->next){
          slow = slow->next;
          fast = fast->next->next;
     }
      Node<int> *newhead = slow->next;
      slow->next = NULL;
     return newhead;
}

Node<int> *merge(Node<int> *first_half, Node<int> *second_half){

     if(!first_half)
          return second_half;

     if(!second_half)
          return first_half;

     Node<int> *head = NULL;
     Node<int> *ptr = NULL;

     while(first_half && second_half){
          if(first_half->data < second_half->data){
               if(!head){
                    head = first_half;
                    ptr = first_half;
                    first_half = first_half->next;
               }else{
                    ptr->next = first_half;
                    first_half = first_half->next;
                    ptr = ptr->next;
               }
          }
          else{
               if(!head){
                    head = second_half;
                    ptr  = second_half;
                    second_half = second_half->next;
               }
               else{
                    ptr->next = second_half;
                    second_half = second_half->next;
                    ptr = ptr->next;
               }
          }
     }

     while(first_half){
          ptr->next = first_half;
          first_half = first_half->next;
          ptr = ptr->next;
     }

     while(second_half){
          ptr->next = second_half;
          second_half = second_half->next;
          ptr = ptr->next;
     }
     return head;
}

Node<int> *mergeSort(Node<int> *head){
     if(!head || !head->next)
          return head;
     Node<int> *first_half = head;
     Node<int> *second_half = DivideList(head);
     first_half = mergeSort(first_half);
     second_half = mergeSort(second_half);
     return merge(first_half,second_half);
}

void display(Node<int> *head){
     if(!head)
          return;
     while(head){
          std::cout << head->data << ' ';
          head = head->next;
     }
     std::cout << '\n';
}

int main(){

     Node<int> *head = NULL;
     while(true){
          int element;
          cin >> element;
          if(element == -1)
               break;
          head = insert(head,element);
     }

     head = mergeSort(head);
     display(head);
}
