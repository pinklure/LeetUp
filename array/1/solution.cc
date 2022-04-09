#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::vector<std::tuple<int, int>> nums_copy{};
    for (int i = 0; i < nums.size(); i++) {
      nums_copy.push_back(std::make_tuple(i, nums[i]));
    }
    std::sort(nums_copy.begin(), nums_copy.end(),
	      [](std::tuple<int, int> const& left,
		 std::tuple<int, int> const& right) {
		return std::get<1>(left) < std::get<1>(right);
	      });

    /* for (auto it : nums_copy) { */
    /*   std::cout << std::get<0>(it) << ":" << std::get<1>(it) << std::endl; */
    /* } */

    int left = 0, right = nums_copy.size() - 1;
    while (left < right) {
      auto diff =
	  target - std::get<1>(nums_copy[left]) - std::get<1>(nums_copy[right]);
      if (diff < 0)
	right--;
      else if (diff > 0)
	left++;
      else
	break;
    }

    return std::vector<int>{std::get<0>(nums_copy[left]),
			    std::get<0>(nums_copy[right])};
  }
};

int main() {
  std::vector<int> tmp{3,2,4};
  Solution test;
  auto res =test.twoSum(tmp, 6);

	for(auto it: res) {
		std::cout<<it<<std::endl;
	}
}
