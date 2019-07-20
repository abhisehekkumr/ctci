/*
     given ant on the infinite grid print the first k step teken by ant where ant
     follows folloing rules

     at white flip the color turn 90 clockwise move ahead
     at black flip the color tuen 90 anticlockwise move ahead
*/
#include<iostream>
using namespace std;

char turn(bool clockwise, char direction){

     if(clockwise){
          if(direction == 'e')
               return 's';
          if(direction == 'n')
               return 'e';
          if(direction == 'w')
               return 'n';
          if(direction == 's')
               return 'w';
     }

     else {

          if(direction == 'e')
               return 'n';
          if(direction == 'n')
               return 'w';
          if(direction == 'w')
               return 's';
          if(direction == 's')
               return 'e';
     }
     return 'n';
}

void solve(bool **arr, bool **path, int i, int j, int &count,int k,char facing = 'e'){
     //std::cout << i << " " << j << " " << facing << '\n';
     // current block is black make it white turn 90 anticlockwise and move
     char direction;
     if(arr[i][j] == false){
          direction = turn(arr[i][j],facing);
          arr[i][j] = true;
     }
     // current block is white make it black turn 90 clockwise and move ahead
     else{
          direction = turn(arr[i][j], facing);
          arr[i][j] = false;
     }

     if(count == k)
          return;

     path[i][j] = true;
     count++;
     if(direction == 'e')
          solve(arr,path,i,j+1,count,k,direction);
     else if(direction == 'n')
          solve(arr,path,i-1,j,count,k,direction);
     else if(direction == 'w')
          solve(arr,path,i,j-1,count,k,direction);
     else
          solve(arr,path,i+1,j,count,k,direction);
}

void printBoard(int k){
     bool **arr = new bool*[2*k];
     int row = 0, col = 1;
     for(int i = 0; i < 2*k; i++){
          arr[i] = new bool[2*k];
          for(int j = 0; j < 2*k; j++){
               if(col%2 == 0)
                    arr[i][j] = false;
               else
                    arr[i][j] = true;
               col++;
          }
          row++;
          if(row%2 == 0)
               col = 0;
          else
               col = 1;
     }

     bool **path = new bool*[2*k];
     for(int i = 0; i < 2*k; i++){
          path[i] = new bool[2*k];
          for(int j = 0; j < 2*k; j++)
               path[i][j] = false;
     }
     int count = 0;
     solve(arr,path,k-1,k-1,count,k);

     for(int i = 0; i < 2*k; i++){
          for(int j = 0; j < 2*k; j++)
               std::cout << path[i][j] << ' ';
          std::cout << '\n';
     }
}

int main(){
     int k;
     cin >> k;
     printBoard(k);
}
