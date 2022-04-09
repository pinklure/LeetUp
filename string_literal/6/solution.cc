#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		std::vector<std::string> container(numRows);
		if(numRows<=1) return s;
		
		for(std::size_t i=0; i<s.size(); i++)
		{
			std::size_t idx = i % (2*(numRows-1));
			if(idx >= numRows - 1)
				idx = 2*(numRows - 1) -idx;
			container[idx].push_back(s[i]);
		}

		for(std::size_t i=1; i<numRows; i++)
			container[0].append(container[i]);
		return container[0];
    }
};

int main()
{
	Solution test;
	/* std::cout<<test.convert("paypalishiring", 3)<<std::endl; */
	std::cout<<test.convert("Apalindromeisaword,phrase,number,orothersequenceofunitsthatcanbereadthesamewayineitherdirection,withgeneralallowancesforadjustmentstopunctuationandworddividers."
, 2)<<std::endl;
	/* int num = 0; */
	/* std::cin>>num; */
	/* for(int i=0; i<50; i++) */
	/* { */
	/* 	int left = i%(2*num); */
	/* 	if(left<=num) */
	/* 		std::cout<<left<<std::endl; */
	/* 	else */
	/* 		std::cout<<2*num-left<<std::endl; */
	/* } */
	return 0;
}
