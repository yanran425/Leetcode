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
            dfs(pos + 1, rest - candidates[pos]);
            sequence.pop_back();
            pos++;
            while ((pos < candidates.size()) && (candidates[pos] == candidates[pos - 1]))
            {
                pos++;
            }
            if (pos < candidates.size())
            {
                dfs(pos, rest);
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        this->candidates = candidates;
        dfs(0, target);
        return res;
    }
};
