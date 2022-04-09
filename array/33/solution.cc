#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
   int binarySearch(std::vector<int>& nums, int begin, int end, int target) {
     if(begin>end) return -1;
     if(nums[begin]==target) return begin;
     if(nums[end]==target) return end;

     auto mid = (begin + end)/2;
     if(nums[mid]>target) {
       return binarySearch(nums, begin, mid-1, target);
     } else if(nums[mid]<target) {
       return binarySearch(nums, mid+1, end, target);
     } else {
       return mid;
     }
   }

   int search(vector<int>& nums, int target) {
     int begin{0}, end{nums.size()-1}, mid{(nums.size()-1)/2};
     if (nums[begin] < nums[end])
       return binarySearch(nums, begin, end, target);
     if(nums[begin]==target) return begin;
     if(nums[end]==target) return end;
     if(target>nums[begin])  {
       if(nums[mid]<nums[end]) {
         while(nums[mid]<nums[end])
           mid--;
         if(nums[mid]==target) return mid;
         else return binarySearch(nums, begin+1, mid);
       } else {

       }
     }

   }
};

int main() {
  std::vector<int> tmp{1,2,3,4,34,54,324,325,655,2313};
  Solution test;
  std::cout<<test.binarySearch(tmp, 0, tmp.size()-1, 2)<<std::endl;
}
