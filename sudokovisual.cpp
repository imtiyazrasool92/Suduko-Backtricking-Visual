#include <bits/stdc++.h>
#include <thread>         
#include <chrono>

#define N 9

using namespace std;

void visual(int arr[N][N]){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << arr[i][j] << " ";
        }
         cout << endl;
    }
}

bool isSafe(int grid[N][N], int row, 
                       int col, int num)
{
     
    for (int x = 0; x <= 8; x++)
        if (grid[row][x] == num)
            return false;
    for (int x = 0; x <= 8; x++)
        if (grid[x][col] == num)
            return false;
    int startRow = row - row % 3, 
            startCol = col - col % 3;
   
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + 
                            startCol] == num)
                return false;
 
    return true;
}

bool grid(int arr[N][N]){
  int row = -1;
  int column = -1;
  bool found = false;
  for(int i=0;i<N;i++){
      for(int j=0;j<N;j++){
          if(arr[i][j]==0){
              row = i;
              column = j;
              found = true;
              break;
          }
      }
      if(found){
          break;
      }
  }
  if(!found){
      return true;
  }
  for(int i=1;i<=N;i++){
      if(isSafe(arr,row,column,i)){
          arr[row][column] = i;
            system("clear");
            visual(arr);
            this_thread::sleep_for (std::chrono::seconds(1));
          if(grid(arr)){
              return true;
          }
          
          arr[row][column] = 0;
            system("clear");
            visual(arr);
            this_thread::sleep_for (std::chrono::seconds(1));
      }
  }
  return false;
}

int main(){
    int gridd[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 },
                       { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
                       { 0, 8, 7, 0, 0, 0, 0, 3, 1 },
                       { 0, 0, 3, 0, 1, 0, 0, 8, 0 },
                       { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
                       { 0, 5, 0, 0, 9, 0, 6, 0, 0 },
                       { 1, 3, 0, 0, 0, 0, 2, 5, 0 },
                       { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
                       { 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
    grid(gridd);
    system("clear");
    visual(gridd);
    return 0;
}