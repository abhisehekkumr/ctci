/*
     given deck of 52 card, shuffle them which should be perfect, means that
     choosing for any for ith location should be equal
*/

#include<iostream>
#include<random>
#define UPPER 52
#define LOWER 1
using namespace std;

int RandomNumber(int lower, int upper){
     double number = ((double)(rand())/RAND_MAX)*(upper - lower + 1);
     return (int)number;
}


// shuffle iterative
void iterative(int cards[]){
     for(int i = 0; i < UPPER; i++){
          int rand = RandomNumber(0,i);
          int temp = cards[rand];
          cards[rand] = cards[i];
          cards[i] = temp;
     }

     for(int i = 0; i < UPPER; i++)
          std::cout << cards[i] << ' ';
     std::cout << '\n';
}

// recursive
void recursive(int cards[], int i = UPPER - 1){
     if(i == 0)
          return;
     recursive(cards,i-1);
     int rand = RandomNumber(0,i);
     int temp = cards[rand];
     cards[rand] = cards[i];
     cards[i] = temp;
}

// my inital solution, rather then for ith range find the suffle for entire range
void shuffle(int cards[]){
     for(int i = 0; i < UPPER; i++){
          int rand = RandomNumber(LOWER,UPPER);
          int temp = cards[rand];
          cards[rand] = cards[i];
          cards[i] = temp;
     }

     for(int i = 0; i < UPPER; i++)
          std::cout << cards[i] << ' ';
     std::cout << '\n';
}

int main(){
     int cards[UPPER];
     for(int i = 0; i < UPPER; i++)
          cards[i] = LOWER + i;
     iterative(cards);
     shuffle(cards);
     recursive(cards);

     for(int i = 0; i < UPPER; i++)
          std::cout << cards[i] << ' ';
     std::cout << '\n';
}
