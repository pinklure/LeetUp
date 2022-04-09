#include <iostream>
#include <string>
#include <vector>
/* #include <array> */
using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    std::vector<std::vector<int>> dp(
        word1.size() + 1, std::vector<int>(word2.size() + 1, 0));
		/* auto DisplayDP = [&dp, &word1, &word2]() { */
		/* 	std::cout<<"Word1: "<<word1<<"\n"; */
		/* 	std::cout<<"Word2: "<<word2<<"\n"; */
		/* 	for(auto &it : dp) { */
		/* 		for(auto &j : it) { */
		/* 			std::cout << j<<" "; */
		/* 		} */
		/* 		std::cout<<"\n"; */
		/* 	} */
		/* 		std::cout<<std::endl; */
		/* 		getchar(); */
		/* }; */
    for (std::size_t i = 1; i <= word1.size(); i++) {
      dp[i][0] = i;
    }
    for (std::size_t i = 1; i <= word2.size(); i++) {
      dp[0][i] = i;
    }

		/* DisplayDP(); */
    for (std::size_t i = 1; i <= word1.size(); i++) {
      for (std::size_t j = 1; j <= word2.size(); j++) {
        dp[i][j] = std::min(std::min(dp[i - 1][j] + 1, dp[i][j - 1]+1),
                            dp[i - 1][j - 1] +
                                int(word1[i - 1] != word2[j - 1]));
      }
			/* DisplayDP(); */
    }
    return dp[word1.size()][word2.size()];
  }
};

int main() {
  Solution test;
	/* std::cout << test.minDistance("horse", "ros") << std::endl; */
  std::cout << test.minDistance("intention", "execution") << std::endl;
}
