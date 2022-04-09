#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	/* string longestPalindrome(string s) { */
	/* 	std::vector<std::vector<bool>> matrix(s.size(), std::move(std::vector<bool>(s.size()))); */
	/* 	if(s.length()==0) return std::string(""); */

	/* 	std::size_t max_i=0, max_len=1; */
	/* 	for(std::size_t i = 0; i<s.size(); i++) */
	/* 	{ */
	/* 		matrix[i][i]=true; */
	/* 		if(s[i]==s[i+1]) */
	/* 		{ */
	/* 			matrix[i][i+1] = true; */
	/* 			max_i = i; */
	/* 			max_len = 2; */
	/* 		} else { */
	/* 			matrix[i][i+1] = false; */
	/* 		} */
	/* 	} */

	/* 	for(std::size_t offset = 2; offset<s.size(); offset++) */
	/* 	{ */
	/* 		for(std::size_t i = 0; i+offset < s.size(); i++) */
	/* 		{ */
	/* 			matrix[i][i+offset] = matrix[i+1][i+offset-1] && s[i] == s[i+offset]; */
	/* 			if(matrix[i][i+offset] && offset+1 > max_len) */
	/* 			{ */
	/* 				max_i = i; */
	/* 				max_len = offset+1; */
	/* 			} */
	/* 		} */
	/* 	} */

	/* 	return s.substr(max_i, max_len); */
    /* } */
	pair<int, int> expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); ++i) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }

};

int main()
{
	Solution test;
	std::cout<<test.longestPalindrome(std::string("babad"))<<std::endl;
	std::cout<<test.longestPalindrome(std::string("cbbd"))<<std::endl;
	std::cout<<test.longestPalindrome(std::string("aaa"))<<std::endl;

}
