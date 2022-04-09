#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
  int lengthOfLastWord(string s) {
		int res{};
		for(auto it=s.rbegin(); it!=s.rend(); it++) {
			if(*it==' ') {
				if(res==0) continue;
				else return res;
			} else res++;
		}
		return res;
	}
};

int main() { Solution test; 
	std::cout<<test.lengthOfLastWord("hasud uqhwu has daush  ")<<std::endl;
}
