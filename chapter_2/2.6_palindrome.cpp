/*
     check if given list is palindrome or not
*/

#include<iostream>
#include<stack>
using namespace std;

struct Node {
     int data;
     Node *next;

     Node(int data){
          this->data = data;
          this->next = NULL;
     }
};

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
          head = head->next;
     }
     std::cout << '\n';
}

Node *reverse(Node *head){
     if(!head || !head->next)
          return head;

     Node *current = head;
     Node *next = NULL;
     Node *prev = NULL;

     while(current){
          next = current->next;
          current->next = prev;
          prev = current;
          current = next;
     }
     return prev;
}

Node *DivideList(Node *head){
     if(!head || !head->next)
          return head;

     Node *slow = head;
     Node *fast = head->next;

     while(fast && fast->next){
          slow = slow->next;
          fast = fast->next->next;
     }
     Node *node = slow->next;
     slow->next = NULL;
     return reverse(node);
}

// most optimal approach with constant space complexity
bool isPalindrome(Node *head){
     if(!head || !head->next)
          return true;

     Node *first = head;
     Node *second = DivideList(head);

     while(first && second){
          if(first->data != second->data)
               return false;
          first = first->next;
          second = second->next;
     }
     return true;
}

// O(n) space complexity good approach but not optimal though
bool isPalindromeNewList(Node *head){
     if(!head  || !head->next)
          return head;

     Node *list = NULL;
     Node *ptr = head;
     while(ptr){
          list = insert(list,ptr->data);
          ptr = ptr->next;
     }
     list = reverse(list);
     Node *ptr1 = list;
     Node *ptr2 = head;

     while(ptr1 && ptr2){
          if(ptr1->data != ptr2->data)
               return false;
          ptr1 = ptr1->next;
          ptr2 = ptr2->next;
     }
     return true;
}

int length(Node *head){
     if(!head)
          return 0;

     int count = 0;
     while(head){
          count += 1;
          head = head->next;
     }
     return count;
}

// worst O(n*n) solution but constant space complexity
bool isPalindromeWorst(Node *head){
     if(!head || !head->next)
          return true;
     int n = length(head);
     int l = n;
     Node *ptr1 = head;
     for(int i = 0; i < l/2; i++){
          Node *ptr2 = head;
          for(int j = 0; j < n; j++){
               if(j == n-1 && ptr1->data != ptr2->data)
                    return false;
               ptr2 = ptr2->next;
          }
          n -= 1;
          ptr1 = ptr1->next;
     }
     return true;
}


// awesome approach but still O(n) space complexity though
// using stack
bool isPalindromeStack(Node *head){
     stack<Node *> s;
     Node *ptr = head;
     while(ptr){
          s.push(ptr);
          ptr = ptr->next;
     }

     while(!s.empty()){
          if(s.top()->data != head->data)
               return false;
          head = head->next;
          s.pop();
     }
     return true;
}

class Result{
public:
     bool flag;
     Node *node;

     Result(Node *node, bool flag){
          this->node = node;
          this->flag = flag;
     }
};

Result *isPalindromeRecursive(Node *head, int n){
     if(n == 0 || !head)
          return new Result(head,true);

     if(n == 1)
          return new Result(head->next,true);

     Result *ans = isPalindromeRecursive(head->next,n-2);
     if(ans->flag == false)
          return ans;

     bool flag = (head->data == ans->node->data);
     Node *node = ans->node->next;
     return new Result(node,flag);
}

// fucking awesome approach
bool isPalindromeAwsome(Node *head){
     if(!head || !head->next)
          return true;
     int n = length(head);
     Result *result = isPalindromeRecursive(head,n);
     return result->flag;
}

int main(){
     Node *head = NULL;
     while(true){
          int element;
          cin >> element;
          if(element == -1)
               break;
          head = insert(head,element);
     }
     //head = DivideList(head);
     //display(head);
     std::cout << isPalindromeAwsome(head) << '\n';
}
