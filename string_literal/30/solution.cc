#include <iostream>
#include <string>
#include <vector>
#include <string_view>

using namespace std;

class Solution {
public:

int word_cnt;
int word_len;
int substr_len;
int slide_len;

std::vector<int> BuildNext(std::string const& pattern) {
	std::vector<int> res(pattern.size(), 0);
	int i=0, j=1;
	while(j!=pattern.size()) {
		if(pattern[i]==pattern[j]) {
		// 相等，若text与pattern比较过程中，pattern自匹配
		// 在j+1处匹配失败
		// 则j处必然匹配成功（i>=0），则下次匹配应该是
		// pattern[j+1]与text[i+1]
			i++;
			res[j]=i;
			j++;
		} else {
		// 若i不为0，说明[0~i-1]之间仍然有避免最坏情况(回退到0)的机会
			if(i!=0) i=res[i-1]; 
		// i已经为0，已经是最坏情况，j不等了
			else j++;
		}
	}
	return res;
}

int Kmp(std::string::iterator begin, decltype(begin) end, std::string const &str) {
	if(begin+str.size()>end) return -1;

	auto&& next = BuildNext(str);
	int i=0, j=0;

	while(j!=str.size()) {
		if(*(begin+i)==str[j]) {
			i++, j++;
		} else {
			if(j!=0) j=next[j-1];
			else i++;

			if(str.size()-j > end-begin-i)
				break;
		}
	}
	if(j==str.size()) return i-j;
	else return -1;
}

int Match(std::string::iterator begin, decltype(begin) end,
		std::string const& str, std::vector<bool> &record) {
	while(true) {
		auto offset = Kmp(begin, end, str);
		if(offset!=-1 && record[offset]==true) {
			begin=begin+offset+word_len;
		} else {
			return offset;
		}
	}
}

public:
vector<int> findSubstring(string s, vector<string> &words) {
	word_cnt = words.size();
	word_len = words.data()->size();
	substr_len = word_cnt * word_len;
	slide_len = s.size() - substr_len ;
	std::vector<int> res{};
	for(int i=0; i< slide_len; i++) {
		std::vector<bool> record(substr_len, false);
		int count=0;
		for(auto& it : words) {
			// 返回第一个匹配的偏移量，单词先后顺序不影响结果
			auto offset = Match(s.begin() + i, s.begin()+i+substr_len, it, record);
			if(offset==-1 || offset%word_len!=0) break; // 若未找到对应位置或未对齐，可直接判断该窗口不符合要求
			else count++;
		}
		if(count==word_cnt) {
			res.push_back(i);
			res.push_back(i+substr_len);
			break;
		}
	}
	return res;
}
};

int main() {
	Solution test;
	auto&& next = test.BuildNext("112313");
	for(auto n_it : next) {
		std::cout<<n_it<<" ";
	}
	std::cout<<std::endl;
}
