#include <algorithm>
#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

class Solution {
public:

    void dfs(std::vector<int> &candidates, int target,
             std::vector <std::vector<int>> &ans, std::vector<int> &combine,
             int idx) {
        if (idx == candidates.size())
            return;

        if (target == 0) {
            ans.push_back(combine);
            return;
        }

        dfs(candidates, target, ans, combine, idx + 1);
        if (target - candidates[idx] >= 0) {
            combine.push_back(candidates[idx]);
            dfs(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }

    vector <vector<int>> combinationSum(vector<int> &candidates, int target) {
        std::vector <std::vector<int>> ans;
        std::vector<int> combine;
        dfs(candidates, target, ans, combine, 0);
        return ans;
    }
};

int main() {
    std::vector<int> tmp{};
    Solution test;
}
