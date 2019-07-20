/*
     given number print its english phrase
*/

#include<iostream>
#include<string>
using namespace std;

void printPhrase(long n, string *numbers, string *tens, string *bigs){
     int count = -1;
     if(n < 20){
          std::cout << numbers[n] << '\n';
          return;
     }

     long number = n;
     while(number){
          number = number/10;
          count += 1;
     }

     while(count){

          if(n == 0)
               return;

          if(n < 20){
               std::cout << numbers[n] << ' ';
               return;
          }

          if(count == 1){
               std::cout << tens[n/10] << ' ';
               count -= 1;
               n = n%10;
               count -= 1;
          }

          if(count == 2){
               if((n/100) != 0)
                    std::cout << numbers[(n/100)] << ' ' << bigs[0] << " ";
               n = n%100;
               count -= 1;
          }

          if(count == 3){
               std::cout << numbers[(n/1000)] << " " << bigs[1] << " ";
               n = n%1000;
               count -= 1;
          }

          if(count == 4){
               int number = n/1000;

               if(number < 20){
                    std::cout << numbers[number] << ' ' << bigs[1] << " ";
                    n = n % 1000;
                    count -= 2;
               }
               else{
                    std::cout << tens[number/10] << ' ';
                    count -= 1;
                    n = n%10000;
               }
          }

          if(count == 5){
               printPhrase(n/1000,numbers,tens,bigs);
               std::cout << bigs[1] << ' ';
               n = n%1000;
               count = 2;
          }

          if(count == 6){
               std::cout << numbers[n/1000000] << ' ' << bigs[2] << " ";
               count -= 1;
               n = n%1000000;
          }

          if(count == 7){
               int number = n/1000000;
               if(number < 20){
                    std::cout << numbers[number] << ' ' << bigs[2] << " ";
                    n = n%1000000;
                    count -= 2;
               }
               else{
                    std::cout << tens[number/10] << ' ';
                    n = n%10000000;
                    count -= 1;
               }
          }

          if(count == 8){
               printPhrase(n/1000000,numbers,tens,bigs);
               std::cout << bigs[2] << ' ';
               n = n%1000000;
               printPhrase(n/1000,numbers,tens,bigs);
               std::cout << bigs[1] << ' ';
               n = n%1000;
               count = 2;
          }

          if(count == 9){
               std::cout << numbers[n/1000000000] << ' ' << bigs[3] << ' ';
               count -= 1;
               n = n % 1000000000;
          }

          if(count == 10){
               int number = n/1000000000;
               if(number < 20){
                    std::cout << numbers[number] << ' ' << bigs[3] << " ";
                    n = n%1000000000;
                    count -= 2;
               }

               else{
                    std::cout << numbers[number/10] << ' ' << bigs[3] << " ";
                    n = n%10000000000;
                    count -= 1;
               }

               //std::cout << count << " " << n << '\n';
          }

          if(count == 11){
               printPhrase(n/1000000000,numbers,tens,bigs);
               std::cout << bigs[3] << ' ';
               n = n%1000000000;
               printPhrase(n/1000000,numbers,tens,bigs);
               std::cout << bigs[2] << ' ';
               n = n%1000000;
               count = 5;
          }
     }
}

int main(){
     string numbers[] = {"zero","one","two","three","four","five","six","seven",
                         "eight","nine","ten","eleven","twelve","thirteen",
                         "fourteen","fiftheen","sixteen","seventeen","eighteen",
                         "nineteen"};

     string tens[] = {"","ten","twenty","thirty","fourty","fifty","sixty",
                      "seventy", "eighty","ninty"};

     string bigs[] = {"hundred","thousand","million","billion"};

     long n;
     cin >> n;
     printPhrase(n,numbers,tens,bigs);
     std::cout << '\n';
}
