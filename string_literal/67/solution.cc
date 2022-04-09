#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
  uint8_t toInt(char const c) { return c - '0'; }

public:
  string addBinary(string a, string b) {
    auto len = std::max(a.size(), b.size()) + 1;
    std::vector<uint8_t> res(len, 0);

    for (std::size_t i = 0; i < len; i++) {
      if (i < a.size())
        res[i] += toInt(a[a.size() - i - 1]);
      if (i < b.size())
        res[i] += toInt(b[b.size() - i - 1]);
    }

    for (std::size_t i = 0; i < res.size() - 1; i++) {
      res[i + 1] += res[i] / 2;
      res[i] = res[i] % 2;
    }

    bool allZero = true;
    std::string ret{};

    for (auto it = res.crbegin(); it != res.crend(); it++) {
      if (allZero && *it == 0)
        continue;
      allZero = false;
      ret.push_back((*it) + '0');
    }
    if (allZero)
      ret.push_back('0');
    return ret;
  }
};

int main() {
  Solution test;
  /* std::cout << test.addBinary("11", "1")<<std::endl; */
  std::cout << test.addBinary("1010", "1011") << std::endl;
  std::cout << test.addBinary("000", "000") << std::endl;
}
