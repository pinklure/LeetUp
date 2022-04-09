#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
private:

std::vector<std::size_t> BuildNext(std::string const &pattern) {
	// res 全部填0，因为后续赋值操作不会涉及所有值
	std::vector<std::size_t> res(pattern.size(), 0);
	std::size_t i=0, j=1; // i is the left ptr, j is the right ptr

	while(j<pattern.size()) {
		if(pattern[j]==pattern[i]) {
			res[j] = ++i;
			j++;
		} else {
			if(i!=0) i = res[i]; // 若i不为0，则i回退
			else j++; // 若i为0，说明res[j]在此处为0，尝试匹配j+1
		}

	}
}

int KMP(std::string const &text, std::string const &pattern) {

}

public:
	int strStr(string haystack, string needle) {
		return KMP(haystack, needle);
    }
};

int main()
{
	Solution test;
}
