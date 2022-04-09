#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestValidParentheses(string s) {
	std::stack<int> ss;
	std::size_t max_size = 0;

	for (std::size_t i = 0; i < s.size(); i++) {
	    if (s[i] == '(' || ss.empty()) {
		ss.push(i);
	    } else {
		if (s[ss.top()] == '(') {
		    ss.pop();
		    if (ss.empty()) {
			max_size = std::max(max_size, i + 1);
		    } else {
			max_size = std::max(max_size, i - ss.top());
		    }
		} else {
		    ss.push(i);
		}
	    }
	}
	return max_size;
    }
};

int main() {
    Solution test;
    std::cout << test.longestValidParentheses("(()") << std::endl;
    std::cout << test.longestValidParentheses(")()())") << std::endl;
    std::cout << test.longestValidParentheses("()(()") << std::endl;
}
