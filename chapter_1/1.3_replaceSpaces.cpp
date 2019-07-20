/*
write a method to replace all spaces in string with %20 char array
*/
#include<iostream>
using namespace std;

// this function useses extra O(n) space which is not optimal
// time complexity is O(n)
void replaceSpaces(char arr[]){
     int count = 0;
     int i = 0;

     while(arr[i] != '\0')
          if(arr[i++] == ' ')
               count += 1;
     char temp[i + 2*count];

     i = 0;
     int j = 0;
     while(arr[i] != '\0'){
          if(arr[i] == ' '){
               temp[j++] = '2';
               temp[j++] = '0';
               temp[j++] = '%';
               i++;
          }

          else
               temp[j++] = arr[i++];
     }

     for(int i = 0; i < j; i++)
          arr[i] = temp[i];
     arr[j] = '\0';
}

// this is optimal O(n)time complexity and O(1) space complexity
void replaceSpaces_optimal(char arr[]){
     int i = 0;
     int count = 0;

     while(arr[i] != '\0')
          if(arr[i++] == ' ')
               count++;
     int index = i + 2*count;
     while(i >= 0){
          if(arr[i] == ' '){
               arr[index] = '%';
               arr[index-1] = '0';
               arr[index-2] = '2';
               index -= 3;
               i--;
          }
          else{
               arr[index] = arr[i--];
               index -= 1;
          }
     }
     //arr[index] = '\0';
}

int main(){
     char arr[100];
     cin.getline(arr,100);
     replaceSpaces_optimal(arr);
     std::cout << arr << '\n';
}
