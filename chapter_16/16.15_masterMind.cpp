/*
     given two strings find total number of hits and psedo_hits, where hit is
     when we have same character in same position and psedo_hits is when same
     character is at another place , note that hit cannot be psedo_hits
*/

#include<iostream>
using namespace std;

void printHits(char *solution, char *guess){
     int hits = 0;
     int psedo_hits = 0;

     int r = 0, g = 0, b = 0, y = 0;
     int s_r = 0, s_g = 0, s_b = 0, s_y = 0;

     for(int i = 0; i < 5; i++){

          if(solution[i] == guess[i]){
               hits += 1;
          }

          else{
               switch(solution[i]){
                    case 'r':
                         s_r += 1;
                         break;
                    case 'g':
                         s_g += 1;
                         break;
                    case 'b':
                         s_b += 1;
                         break;
                    case 'y':
                         s_y += 1;
                         break;
               }

               switch(guess[i]){
                    case 'r':
                         r += 1;
                         break;
                    case 'g':
                         g += 1;
                         break;
                    case 'b':
                         b += 1;
                         break;
                    case 'y':
                         y += 1;
                         break;
               }
          }
     }

     psedo_hits += min(s_r,r);
     psedo_hits += min(s_g,g);
     psedo_hits += min(s_b,b);
     psedo_hits += min(s_y,y);

     std::cout << hits -1 << " " << psedo_hits << '\n';
}

int main(){
     char solution[5],guess[5];
     cin.getline(solution,5);
     cin.getline(guess,5);

     printHits(solution,guess);
}
