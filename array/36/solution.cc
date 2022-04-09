#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
   bool isValidSudoku(vector<vector<char>>const& board) {
     std::vector<std::vector<bool>> rows(9, std::vector<bool>(9, false));
     std::vector<std::vector<bool>> cols(9, std::vector<bool>(9, false));
     std::vector<std::vector<std::vector<bool>>> subboxes(3, std::vector<std::vector<bool>>(3, std::vector<bool>(9, false)));

     for(auto i=0; i<9; i++) {
       for(auto j=0; j<9; j++) {
         char c = board[i][j];
         if(c!='.') {
           int idx = c - '0' - 1;
           if(rows[i][idx] || cols[j][idx] || subboxes[i/3][j/3][idx])
             return false;
           rows[i][idx] = true;
           cols[j][idx] = true;
           subboxes[i/3][j/3][idx] = true;
         }
       }
     }

     return true;
   }
};

int main() {
  std::vector<int> tmp{};
  Solution test;
  test.isValidSudoku();
}
