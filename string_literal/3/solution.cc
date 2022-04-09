#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	// return new begin
	// range [begin, end)
	/* std::size_t CharInString(string const& s, size_t begin, size_t end, char c) */
	/* { */
	/* 	for(std::size_t i = end; i>begin; i--) */
	/* 	{ */
	/* 		if(s[i-1]==c) */
	/* 			return i; */
	/* 	} */
	/* 	return begin; */
	/* } */
	/* int lengthOfLongestSubstring(string s){ */
	/* 	if(s.length()<=1) return s.length(); */
	/* 	size_t i=0, j=1; */
	/* 	size_t max=1; */
	/* 	while(j<s.length()) */
	/* 	{ */
	/* 		i = CharInString(s, i, j, s[j]); */
	/* 		j++; */
	/* 		max = std::max(j-i, max); */
	/* 	} */
	/* 	return max; */
	/* } */

	int lengthOfLongestSubstring(string s){
		if(s.length()<=1) return s.length();
		int begin=0, end=1, max=1;
		/* int map[256] = {-1}; */
		std::vector<int> map(256, -1);
		map[static_cast<int>(s[begin])]=0;
		while(static_cast<size_t>(end)<s.length())
		{
			auto& NextChar = map[static_cast<int>(s[end])];
			begin = std::max(NextChar+1, begin);
			NextChar = end;
			end++;
			max = std::max(end - begin, max);
		}
		return max;
	}
};


int main()
{
	Solution test;
	/* std::cout<<test.lengthOfLongestSubstring(std::string("au"))<<std::endl; */
	std::cout<<test.lengthOfLongestSubstring(std::string("abcabcbb"))<<std::endl;
}
