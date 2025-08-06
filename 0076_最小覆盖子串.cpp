#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool check(unordered_map <char, int>& sm, unordered_map <char, int>& tm) {
        for (const auto& c : tm) {
            if (sm[c.first] < c.second) {
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t) {
        int ssize = s.size();
        int tsize = t.size();
        if (ssize < tsize)
        {
            return "";
        }
        unordered_map <char, int> sm, tm;
        for (char c : t)
        {
            tm[c]++;
        }
        int lindex = 0, rindex = -1, reslindex = 0, resrindex = -1;
        int length = INT_MAX;
        for (int i = 0; i < ssize; i++)
        {
            rindex = i;
            if (find(t.begin(), t.end(), s[i]) != t.end())
            {
                sm[s[i]]++;
            }
            while (check(sm, tm) && lindex <= rindex)
            {
                if (rindex - lindex + 1 < length)
                {
                    reslindex = lindex;
                    resrindex = rindex;
                    length = rindex - lindex + 1;
                }
                if (find(t.begin(), t.end(), s[lindex]) != t.end())
                {
                    sm[s[lindex]]--;
                }
                lindex++;
            }
        }
        return resrindex - reslindex >= 0 ? s.substr(reslindex, length) : "";
    }
};