#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<string>> m;
        int size = strs.size();
        if ((size == 0) || (size == 1))
        {
            res.push_back(strs);
            return res;
        }

        for (int i = 0; i < size; i++)
        {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());
            m[tmp].emplace_back(strs[i]);
        }
        for (auto& mv : m)
        {
            res.emplace_back(mv.second);
        }
        return res;
    }
};