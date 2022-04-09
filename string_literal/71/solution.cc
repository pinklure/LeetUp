#include <iostream>
/* #include <queue> */
/* #include <stack> */
#include <deque>
#include <string>
using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    std::size_t begin = 0;
    std::deque<std::string> ss{};
    for (std::size_t i = 0; i < path.size(); i++) {
      if (path[i] == '/') {
        // 忽略 首个'/', '//', '/./' 的情况
        if (begin == i || (begin + 1 == i && path[begin] == '.')) {
          begin = i + 1;
          continue;
        }

        std::string tmp(path.begin() + begin, path.begin() + i);
        begin = i + 1;

        if (tmp == "..") {
          if (!ss.empty())
            ss.pop_back();
        } else {
          ss.push_back(std::move(tmp));
        }
      } else if (i == path.size() - 1) {
				if(begin == i && path[begin] == '.')
					continue;
        std::string tmp(path.begin() + begin, path.begin() + i + 1);
        if (tmp == "..") {
          if (!ss.empty())
            ss.pop_back();
        } else {
          ss.push_back(std::move(tmp));
        }
      }
    }

    std::string res{};

    for (auto &it : ss) {
      res.push_back('/');
      res.append(it);
    }
    if (res.empty())
      res.push_back('/');
    return res;
  }
};

int main() {
  Solution test;
  std::cout << test.simplifyPath("/wja/ijwq/") << std::endl;
  std::cout << test.simplifyPath("/../") << std::endl;
  std::cout << test.simplifyPath("/home//foo") << std::endl;
  std::cout << test.simplifyPath("/a/./b/../../c/") << std::endl;
  std::cout << test.simplifyPath("/.") << std::endl;
  return 0;
}
