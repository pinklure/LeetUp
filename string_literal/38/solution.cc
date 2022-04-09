#include <iostream>
#include <string>
using namespace std;

class Solution {
   private:
    void Describe(std::string &str) {
		std::string res{};
		int base = 0;
		int i = 0;
		while (true) {
			if(str[i]!=str[base]) {
				res.append(std::to_string(i-base)+str[base]);
				base = i;
			}
			if(i+1==str.size()) {
				res.append(std::to_string(i+1-base)+str[base]);
				break;
			}
			i++;
		}
		str = std::move(res);
    }

   public:
    string countAndSay(int n) {
	std::string res("1");
	for (int i = 1; i < n; i++) {
	    Describe(res);
	}
	return res;
    }
};

int main() { 
	Solution test;
	std::cout<<test.countAndSay(1)<<std::endl;
	std::cout<<test.countAndSay(2)<<std::endl;
	std::cout<<test.countAndSay(3)<<std::endl;
	std::cout<<test.countAndSay(4)<<std::endl;
	std::cout<<test.countAndSay(5)<<std::endl;
	std::cout<<test.countAndSay(6)<<std::endl;
	std::cout<<test.countAndSay(7)<<std::endl;
	std::cout<<test.countAndSay(8)<<std::endl;
	std::cout<<test.countAndSay(9)<<std::endl;
	std::cout<<test.countAndSay(10)<<std::endl;
}
