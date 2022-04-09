#include <assert.h>

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  string multiply(string num1, string num2) {
    std::vector<int> vec_num1{}, vec_num2{};
    std::for_each(num1.rbegin(), num1.rend(),
                  [&vec_num1](char c) { vec_num1.push_back(c - '0'); });
    std::for_each(num2.rbegin(), num2.rend(),
                  [&vec_num2](char c) { vec_num2.push_back(c - '0'); });
    std::vector<int> vec_res(vec_num1.size() + vec_num2.size(), 0);
    for (std::size_t i = 0; i < vec_num1.size(); i++) {
      for (std::size_t j = 0; j < vec_num2.size(); j++) {
        vec_res[i + j] += vec_num1[i] * vec_num2[j];
      }
    }

    for (auto it = vec_res.begin(); it != vec_res.end() - 1; it++) {
      *(it + 1) += *it / 10;
      *it = *it % 10;
    }

		std::size_t i=0;
		for(; i<vec_res.size(); i++) {
			if(*(vec_res.rbegin()+i)!=0) break;
		}
		if(i==vec_res.size()) i--;

		std::string res{};
		for(auto it=vec_res.rbegin()+i; it!=vec_res.rend(); it++) {
			res.push_back(*it + '0');
		}

    return res;
  }
};

int main() {
  Solution test;
  /* test.multiply("123", "456"); */
  std::cout << test.multiply("213", "413") << std::endl;
  std::cout << test.multiply("123", "456") << std::endl;
  std::cout << test.multiply("0", "0") << std::endl;
  std::cout << test.multiply("9", "9") << std::endl;
}
