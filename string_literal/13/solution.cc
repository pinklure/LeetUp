#include <string>
#include <iostream>
#include <map>
using namespace std;

class Solution {
private:
	static std::map<char, int> VALUE;

public:
	int romanToInt(string s) {
		uint16_t res{};
		uint8_t i =0;
		while(i<s.size()) {
			if(i<s.size() && VALUE[s[i+1]]>VALUE[s[i]]) {
				res += VALUE[s[i+1]] - VALUE[s[i]];
				i+=2;
			} else {
				res += VALUE[s[i]];
				i++;
			}
		}
		return res;
    }
};

std::map<char, int> Solution::VALUE {
	{'I', 1},
	{'V', 5},
	{'X', 10},
	{'L', 50},
	{'C', 100},
	{'D', 500},
	{'M', 1000},
};

int main()
{
	Solution test;
	std::cout<<test.romanToInt("IV")<<std::endl;
	std::cout<<test.romanToInt("IX")<<std::endl;
	std::cout<<test.romanToInt("III")<<std::endl;
	std::cout<<test.romanToInt("LVIII")<<std::endl;
	std::cout<<test.romanToInt("MCMXCIV")<<std::endl;
}
