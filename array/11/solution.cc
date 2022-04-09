#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
   int maxArea(vector<int>& height) {
     int i=0, j=height.size()-1;
     int max_res{};

     while(i<j) {
       max_res = std::max((j-i)*std::min(height[i],height[j]), max_res);
       if(height[i]<height[j])
         i++;
       else
         j--;
     }
     return max_res;
   }
};

int main() {
  std::vector<int> tmp{1,8,6,2,5,4,8,3,7};
  Solution test;
  std::cout<<test.maxArea(tmp)<<std::endl;
}
