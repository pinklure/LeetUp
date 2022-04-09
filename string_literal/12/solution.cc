#include <string>
#include <iostream>
using namespace std;

class Solution {
private:

	class ROMA {
		public:
		/* enum { */
		/* 	I,// 1 */
		/* 	V,// 5 */
		/* 	X,// 10 */
		/* 	L,// 50 */
		/* 	C,// 100 */
		/* 	D,// 500 */
		/* 	M,// 1000 */
		/* 	TOP */
		/* }; */
		static char const CHAR [8];
		static int const NUM [7];
	};



public:
	string intToRoman(int num) {
		string res{};
		for(int i = 6; i>=0; i-=2) {
			int factor = num/ROMA::NUM[i];
			switch(factor) {
				case 0:
					continue;
				case 1:
				case 2:
				case 3:
				{
					for(int j=0; j<factor; j++){
						res.push_back(ROMA::CHAR[i]);
					}
					break;
				}
				case 4:
				{
					res.push_back(ROMA::CHAR[i]);
					res.push_back(ROMA::CHAR[i+1]);
					break;
				}
				case 5:
				{
					res.push_back(ROMA::CHAR[i+1]);
					break;
				}
				case 6:
				case 7:
				case 8:
				{
					res.push_back(ROMA::CHAR[i+1]);
					for(int j=5; j<factor; j++){
						res.push_back(ROMA::CHAR[i]);
					}
					break;
				}
				case 9:
				{
					res.push_back(ROMA::CHAR[i]);
					res.push_back(ROMA::CHAR[i+2]);
					break;
				}
				default:
				break;
			}
			num = num - factor*ROMA::NUM[i];
		}
		return res;
    }
};

char const Solution::ROMA::CHAR[] = {
	"I"// 1
	"V"// 5
	"X"// 10
	"L"// 50
	"C"// 100
	"D"// 500
	"M"// 1000
};

int const Solution::ROMA::NUM [] = { 1,5,10,50,100,500,1000 };

int main()
{
	Solution test;
	std::cout<<test.intToRoman(3)<<std::endl;
	std::cout<<test.intToRoman(4)<<std::endl;
	std::cout<<test.intToRoman(9)<<std::endl;
	std::cout<<test.intToRoman(58)<<std::endl;
	std::cout<<test.intToRoman(1994)<<std::endl;
}
