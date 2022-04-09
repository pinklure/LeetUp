#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;


class Solution {
private:
	class Automaton {
	private:
		enum STATE {
			START,
			SIGN,
			NUMBER,
			END			
		};
		int8_t sign {1};
		long long ans {0};
		uint8_t state {START};
		bool overflow{false};

		std::vector<std::vector<uint8_t>> map {
			{ START, SIGN , NUMBER, END   },
			{ END  , END  , NUMBER, END   },
			{ END  , END  , NUMBER, END   },
			{ END  , END  , END   , END   }
		};

		std::size_t getColumn(char c) {
			switch(c) {
				case ' ':
					return 0;
				case '+':
				case '-':
					return 1;
				default:
					if(c>='0' && c<='9')
						return 2;
					else
						return 3;
			}
		}
		
	public:
		bool isEnd(char c) {
			state = map[state][getColumn(c)];
			switch (state) {
				case SIGN:
					if(c=='-') sign = -1;
					break;
				case NUMBER:
					ans = ans*10 + uint32_t(c - '0');
					if((sign == 1 && ans > (long long)INT32_MAX) || (sign == -1 && ans > -(long long)INT32_MIN))
					{
						overflow = true;
						state = END;
					}
					/* if(sign == 1) */
					/* 	ans = min(ans, (long long)INT32_MAX); */
					/* else */
					/* 	ans = min(ans, -(long long)INT32_MIN); */
					break;
			}
			return state == END;
		}
		
		inline int getResult() {
			/* return sign * ans; */
			if(overflow){
				if(sign==1)
					return INT32_MAX;
				else return INT32_MIN;
			} else {
				return sign*ans;
			}
		}
	};

public:
    int myAtoi(string str) {
		Automaton robot;
		for(auto it : str) {
			if(robot.isEnd(it))
				break;
		}
		return robot.getResult();
    }
};
/* class Automaton { */
/*     string state = "start"; */
/*     unordered_map<string, vector<string>> table = { */
/*         {"start", {"start", "signed", "in_number", "end"}}, */
/*         {"signed", {"end", "end", "in_number", "end"}}, */
/*         {"in_number", {"end", "end", "in_number", "end"}}, */
/*         {"end", {"end", "end", "end", "end"}} */
/*     }; */

/*     int get_col(char c) { */
/*         if (isspace(c)) return 0; */
/*         if (c == '+' or c == '-') return 1; */
/*         if (isdigit(c)) return 2; */
/*         return 3; */
/*     } */
/* public: */
/*     int sign = 1; */
/*     long long ans = 0; */

/*     void get(char c) { */
/*         state = table[state][get_col(c)]; */
/*         if (state == "in_number") { */
/*             ans = ans * 10 + c - '0'; */
/*             ans = sign == 1 ? min(ans, (long long)INT32_MAX) : min(ans, -(long long)INT32_MIN); */
/*         } */
/*         else if (state == "signed") */
/*             sign = c == '+' ? 1 : -1; */
/*     } */
/* }; */

/* class Solution { */
/* public: */
/*     int myAtoi(string str) { */
/*         Automaton automaton; */
/*         for (char c : str) */
/*             automaton.get(c); */
/*         return automaton.sign * automaton.ans; */
/*     } */
/* }; */


int main()
{
	Solution test;
	/* std::cout<<test.myAtoi(std::string("words and 987"))<<std::endl; */
	/* std::cout<<test.myAtoi(std::string("127"))<<std::endl; */
	/* std::cout<<test.myAtoi(std::string("  +127"))<<std::endl; */
	/* std::cout<<test.myAtoi(std::string("  -127"))<<std::endl; */
	std::cout<<test.myAtoi(std::string("-91283472332"))<<std::endl;
	std::cout<<test.myAtoi(std::string("91283472332"))<<std::endl;
}
