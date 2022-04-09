#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:
    std::vector<pair<int, int>> freq{};
    std::vector<vector<int>> ans{};
    std::vector<int> sequence{};

    void dfs(int pos, int rest) {
        if(rest == 0) {
            ans.push_back(sequence);
            return;
        }

        if(pos == freq.size() || rest < freq[pos].first)
            return;



    }

    vector <vector<int>> combinationSum2(vector<int> &candidates, int target) {
    }
};

int main() {
    std::vector<int> tmp{};
    Solution test;
}
