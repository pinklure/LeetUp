#include <string>
#include <iostream>
#include <stack>
using namespace std;

class Solution {
private:
	/* static std::unordered_map<char, uint8_t> Cast; */

public:
	bool isValid(string s) {
		std::stack<char> res;
		
		for(auto it : s) {
			switch(it) {
				case '(':
				case '{':
				case '[':
					res.push(it);
					break;
				case ')':
					if(res.empty() || res.top()!='(')
						return false;
					else res.pop();
					break;
				case '}':
					if(res.empty() || res.top()!='{')
						return false;
					else res.pop();
					break;

				case ']':
					if(res.empty() || res.top()!='[')
						return false;
					else res.pop();
					break;
				default:
					break;
			}

		}

		if(res.empty()) return true;
		else return false;
    }
};
/* std::unordered_map<char, uint8_t> Solution::Cast { */
/* 	{'(', 0}, */
/* 	{')', 0}, */
/* 	{'{', 1}, */
/* 	{'}', 1}, */
/* 	{'[', 2}, */
/* 	{']', 2}, */
/* }; */

int main()
{
	Solution test;
	std::cout<<test.isValid("()")<<std::endl;
	std::cout<<test.isValid("()[]{}")<<std::endl;
	std::cout<<test.isValid("(]")<<std::endl;
}
