#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
  vector<string> fullJustify(vector<string> const &words, int maxWidth) {
    std::vector<std::string> result{};
    std::size_t line_begin{}, line_words_len{};
    auto maxWidth_ul = static_cast<std::size_t>(maxWidth);

    for (std::size_t i = 0; i < words.size(); i++) {
      auto this_line_len = line_words_len + words[i].size() + i - line_begin;
      if (this_line_len > maxWidth_ul) {
        auto gaps = i - 1 - line_begin;
        std::size_t pergap_width{};
        if (gaps != 0)
          pergap_width = (maxWidth_ul - line_words_len) / gaps;
        auto over_average_cnt =
            maxWidth_ul - line_words_len - pergap_width * gaps;
        std::string line_result{};
        for (auto it = line_begin; it < i; it++) {
          line_result.append(words[it]);
          for (std::size_t j = 0; it != i - 1 && j < pergap_width; j++)
            line_result.push_back(' ');

          if (over_average_cnt != 0) {
            over_average_cnt--;
            line_result.push_back(' ');
          }
        }
				while (line_result.size() != maxWidth_ul)
					line_result.push_back(' ');
		/* line_result.push_back('"'); */
        result.push_back(std::move(line_result));
        line_begin = i;
        line_words_len = words[i].size();
      } else {
        line_words_len += words[i].size();
      }
    }

    std::string line_result{};
    for (std::size_t i = line_begin; i < words.size(); i++) {
      line_result.append(words[i]);
      if (i != words.size() - 1)
        line_result.push_back(' ');
    }
    while (line_result.size() != maxWidth_ul)
      line_result.push_back(' ');
		/* line_result.push_back('"'); */
    result.push_back(std::move(line_result));
    return result;
  }
};

int main() {
  Solution test;
  /* { */
  /*   auto &&res = test.fullJustify( */
  /*       {"This", "is", "an", "example", "of", "text", "justification."}, 16);
   */
  /*   for (auto &it : res) { */
  /*     std::cout << it << "\n"; */
  /*   } */
  /* } */
  {
    auto &&res = test.fullJustify(
        {"What", "must", "be", "acknowledgment", "shall", "be"}, 16);
    for (auto &it : res) {
      std::cout << it << "\n";
    }
  }
  /* { */
  /*   auto &&res = test.fullJustify( */
  /*       {"Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"},
   * 20); */
  /*   for (auto &it : res) { */
  /*     std::cout << it << "\n"; */
  /*   } */
  /* } */
}
