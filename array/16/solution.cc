#include <algorithm>
#include <iostream>
#include <limits>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
  int findClosest(std::vector<int> const &nums, std::size_t left, std::size_t right, int target) {
    if (left >= right)
      return left;
    auto mid = (left + right) / 2;
    if (nums[mid] < target) {
      return findClosest(nums, mid + 1, right, target);
    } else if (nums[mid] > target) {
      return findClosest(nums, left, mid - 1, target);
    } else
      return mid;
  }

  int threeSumClosest(vector<int> &nums, int target) {
    std::sort(nums.begin(), nums.end());
    //     int min_diff = std::numeric_limits<decltype(min_diff)>::max();
    int closest_sum = nums[0] + nums[1] + nums[2];
    for (std::size_t first = 0; first < nums.size() - 2; first++) {
      while (first + 1 < nums.size() - 2 && nums[first] == nums[first + 1])
        first++;
      for (std::size_t second = first + 1; second < nums.size() - 1; second++) {
        while (second + 1 < nums.size() - 2 && nums[second] == nums[second + 1])
          second++;
        auto t = target - nums[first] - nums[second];
        auto third = findClosest(nums, second + 1, nums.size() - 1, t);
        if (std::abs(target - nums[first] - nums[second] - nums[third]) < std::abs(target - closest_sum))
          closest_sum = nums[first] + nums[second] + nums[third];
        //         min_diff = std::min(min_diff, std::abs(t - nums[findClosest(nums, second+1, nums.size()-1, t)]));
      }
    }
    return closest_sum;
  }
};

int main() {
  //  std::vector<int> tmp{-1,2,1,-4};
  //  std::vector<int> tmp{0,0,0};
  /* std::vector<int> tmp{1,-3,3,5,4,1}; */
  std::vector<int> tmp{-1, 0, 1, 1, 55};
  //  std::sort(tmp.begin(), tmp.end());
  //  for(auto it:tmp)
  //    std::cout<<it<<" ";
  //  std::cout<<std::endl;
  Solution test;
  //  std::cout<<test.findClosest(tmp,0,tmp.size()-1,1);
  std::cout << test.threeSumClosest(tmp, 3);
}
