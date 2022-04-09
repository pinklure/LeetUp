#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
private:
  std::unordered_map<std::string, std::vector<std::string>> _map{};

public:
  vector<vector<string>> groupAnagrams(vector<string> &&strs) {
    while (!strs.empty()) {
      std::string key = strs.back();
      std::sort(key.begin(), key.end());
      _map[key].push_back(strs.back());
      strs.pop_back();
    }
    std::vector<std::vector<std::string>> res{};
    for (auto it = _map.begin(); it != _map.end();) {
      res.push_back(it->second);
      it = _map.erase(it);
    }
    return res;
  }
};

int main() {
  Solution test;
  auto &&ret = test.groupAnagrams({"eat", "tea", "tan", "ate", "nat", "bat"});
	for(auto& it:ret) {
		for(auto& sub:it) {
			std::cout<<sub<<" ";
		}
		std::cout<<std::endl;
	}
}
