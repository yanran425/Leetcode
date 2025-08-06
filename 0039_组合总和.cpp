#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
private:
    vector<int> candidates;
    vector<vector<int>> res;
    vector<int> sequence;

public:
    void dfs(int pos, int rest) {
        if (pos == candidates.size())
        {
            return;
        }
        if (candidates[pos] > rest)
        {
            return;
        }
        else if (candidates[pos] == rest)
        {
            sequence.push_back(candidates[pos]);
            res.push_back(sequence);
            sequence.pop_back();
            return;
        }
        else
        {
            sequence.push_back(candidates[pos]);
            dfs(pos, rest - candidates[pos]);
            sequence.pop_back();
            dfs(pos + 1, rest);
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        dfs(0, target);
        return res;
    }
};

int main()
{
    vector<int> v;
    v.push_back(2);
    v.push_back(3);
    v.push_back(6);
    v.push_back(7);
    Solution s;
    s.combinationSum(v, 7);
    return 0;
}