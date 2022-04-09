#include <string>
#include <iostream>
#include <vector>
/* #include <map> */
#include <unordered_map>
using namespace std;

class Solution {
private:
	static std::unordered_map<char, std::string> Cast;

	vector<string> stageResult(vector<string>&& lastRes, char nextChar) {
		vector<string> res{};
		for(auto it : Cast[nextChar]) {
			if(lastRes.empty()) {
				res.push_back(std::string(1,it));
				continue;
			}
			for(auto& s: lastRes) {
				string tmp(s);
				tmp.push_back(it);
				res.push_back(std::move(tmp));
			}
		}
		return res;
	}

public:
	vector<string> letterCombinations(string digits) {
		std::vector<std::string> res{};
		for(auto it: digits) {
			res = stageResult(std::move(res), it);
		}
		return res;
    }
};

std::unordered_map<char, std::string> Solution::Cast {
	{'2', "abc"},
	{'3', "def"},
	{'4', "ghi"},
	{'5', "jkl"},
	{'6', "mno"},
	{'7', "pqrs"},
	{'8', "tuv"},
	{'9', "wxyz"},
};

int main()
{
	Solution test;
	auto&& res = test.letterCombinations("23");
	for(auto& it : res) {
		std::cout<<it<<std::endl;
	}

}
