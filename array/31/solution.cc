#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
   void reverseInplace(std::vector<int>& nums, std::size_t left, std::size_t right) {
     while(left<right) {
       std::swap(nums[left], nums[right]);
       left++;
       right--;
     }
   }

   void nextPermutation(vector<int>& nums) {
     std::size_t minor{}, major{};
     std::size_t i{};
     for( i= nums.size()-1; i>0; i--) {
       if(nums[i-1]<nums[i]) {
         minor = i-1;
         break;
       }
     }
     if(i==0) {
       reverseInplace(nums, 0, nums.size()-1);
     } else {
       for(i = nums.size()-1; i>minor; i--) {
         if(nums[i]>nums[minor]) {
           major = i;
           break;
         }
       }
       std::swap(nums[minor], nums[major]);
       reverseInplace(nums, minor+1, nums.size()-1);
     }
   }
};

int main() {
//  std::vector<int> tmp{1,2,3,4,5,6,7,8,9};
//  std::vector<int> tmp{1,2,3};
//  std::vector<int> tmp{3,2,1};
//  std::vector<int> tmp{1,1,5};
  std::vector<int> tmp{2,3,1};
  Solution test;
//  test.reverseInplace(tmp, 0, tmp.size()-1);
  test.nextPermutation(tmp);
  for(auto it: tmp) {
    std::cout<<it<<" ";
  }
  std::cout<<std::endl;
}
