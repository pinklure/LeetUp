#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		std::size_t i=0;
		std::size_t min_len = -1;
		std::string res{};
		for(auto& it : strs)
			min_len = std::min(it.size(), min_len);

		while(i<min_len) {
			char c = strs[0][i];
			bool same = true;
			for(auto& it : strs) {
				if(it[i] != c) {
					same = false;
					break;
				}
			}
			if(same) res.push_back(c);
			else break;
			i++;
		}
		return res;
    }
};

int main()
{
	Solution test;
	std::vector<std::string> strs {
		"flower","flow","flight"
	};
	std::cout<<test.longestCommonPrefix(strs);
}
