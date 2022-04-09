#include <string>
#include <iostream>
#include <vector>
using namespace std;

// 未能处理 A*.... 匹配 AAAAABC等情况
/* class Solution { */
/* private: */
/* 	class Automaton { */
/* 		bool isLetter(string const& s, std::size_t &i, string const& p, std::size_t &j) { */
/* 			if(s[i]==p[j]) { */
/* 				i++,j++; */
/* 				// 字符之间完全匹配 */
/* 				return true; */
/* 			} */
/* 			else if(j+1<p.size() && p[j+1]=='*') { */
/* 				// p 下一个字符为*，p 跳到下一个 Dot/Letter */
/* 				j+=2; // 由于经过compressString()，'*' 之后为 Dot, Letter 或 p末尾 */
/* 				return true; */
/* 			} */
/* 			else return false; */
/* 		} */

/* 		bool isStar(string const& s, std::size_t &i, string const& p, std::size_t &j) { */
/* 			if(s[i]==p[j-1] || p[j-1]=='.') i++; */
/* 			else j++; */
/* 			return true; */
/* 		} */

/* 		inline bool isDot(string const& s, std::size_t &i, string const& p, std::size_t &j) { */
/* 			i++, j++; */
/* 			return true; */
/* 		} */

/* 		public: */
/* 			bool getChar(string const& s, std::size_t &i, string const& p, std::size_t &j) { */
/* 				switch (p[j]) */
/* 				{ */
/* 					case '.': */
/* 						return isDot(s, i, p, j); */
/* 					case '*': */
/* 						return isStar(s, i, p, j); */
/* 					default: */
/* 						return isLetter(s, i, p, j); */
/* 				} */
/* 			} */
/* 	}; */
/* public: */
/* 	// compress pattern string, A*A ==> A*, A*AA ==> A*, A*A* ==> A*, */ 
/* 	void compressString(string& p) { */
/* 		for(std::size_t i = 0; i<p.size(); i++) { */
/* 			if(p[i]=='*') { */
/* 				std::size_t len=0; */
/* 				// i-1 is always in valid range, as the Description said */
/* 				while(i+len+1 < p.size() && (p[i+len+1]=='*'||p[i+len+1]==p[i-1])) { */
/* 					len++; */
/* 				} */
/* 				p.erase(i+1, len); */
/* 			} */
/* 		} */
/* 	} */

/* 	bool isMatch(string s, string p){ */
/* 		Automaton robot; */
/* 		compressString(p); */
/* 		std::size_t i=0, j=0;// iterator: i for s, p for j */
/* 		while(i<s.size() && j<p.size()) { */
/* 			if(!robot.getChar(s, i, p, j)) */
/* 				return false; */
/* 		} */
/* 		if(i==s.size() && (j==p.size() || (j==p.size()-1 && p[j]=='*'))) */
/* 			return true; */
/* 		else return false; */
/* 	} */
/* }; */


class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size();
        int n = p.size();

        auto matches = [&](int i, int j) {
            if (i == 0) {
                return false;
            }
            if (p[j - 1] == '.') {
                return true;
            }
            return s[i - 1] == p[j - 1];
        };

        vector<vector<int>> f(m + 1, vector<int>(n + 1));
        f[0][0] = true;
        for (int i = 0; i <= m; ++i) {
			std::cout<<"============="<<i<<"============"<<std::endl;
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '*') {
                    f[i][j] |= f[i][j - 2];
                    if (matches(i, j - 1)) {
                        f[i][j] |= f[i - 1][j];
                    }
                }
                else {
                    if (matches(i, j)) {
                        f[i][j] |= f[i - 1][j - 1];
                    }
                }
            }
			for(auto& it: f) {
				for(auto n: it) {
					std::cout<<n<<" ";
				}
				std::cout<<"\n";
			}
        }
        return f[m][n];
    }
};

int main()
{
	Solution test;
	/* std::cout<<test.isMatch("aa", "aa")<<std::endl; // t */
	/* std::cout<<test.isMatch("aa", "a")<<std::endl; // f */
	/* std::cout<<test.isMatch("absd","....")<<std::endl; // t */
	/* std::cout<<test.isMatch("absd","a...")<<std::endl; // t */
	/* std::cout<<test.isMatch("absd","a..")<<std::endl; // f */
	/* std::cout<<test.isMatch("absd","a.*")<<std::endl; // t */
	/* std::cout<<test.isMatch("abbsd","a*b...")<<std::endl; // t */
	std::cout<<test.isMatch("abbsd","ab*...")<<std::endl; // t
	std::cout<<test.isMatch("abbsd","ab*..")<<std::endl; // t
	std::cout<<test.isMatch("abbsd","ax*....")<<std::endl; // t


	// test compressString()
	/* std::string str = "A*A*jiA"; */
	/* std::string str = "A*A**hA"; */
	/* std::string str = "A*AAArA"; */
	/* std::string str = "A*Andjas"; */
	/* test.compressString(str); */
	/* std::cout<<str<<std::endl; */
}
