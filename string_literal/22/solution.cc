#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
	std::vector<string> res{};

	void NextStep(string str, int left, int right, char addchar) {
		str.push_back(addchar);
		if(addchar=='(') left--;
		else right--;

		if(left==0 && right==0)
			res.push_back(std::move(str));

		if(left>0) {
			NextStep(str,left,right,'(');
		}

		if(right>left) {
			NextStep(str,left,right,')');
		}

	}

public:
	vector<string> generateParenthesis(int n) {
		int left{n}, right{n};
		std::string str{};
		NextStep(str, left, right, '(');
		return res;
    }

};

int main()
{
	Solution test;
	auto&& res = test.generateParenthesis(3);
	for(auto &it : res) {
		std::cout<<it<<std::endl;
	}
}
