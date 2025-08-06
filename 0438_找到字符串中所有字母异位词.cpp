#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int size1 = s.size();
        int size2 = p.size();
        if (size1 < size2)
            return res;

        sort(p.begin(), p.end());
        bool flag = false;
        for (int i = 0; i <= size1 - size2; i++)
        {
            if (flag)
            {
                if (s[i - 1] == s[i + size2 - 1])
                {
                    res.push_back(i);
                    flag = true;
                }
                else
                {
                    flag = false;
                }
            }
            else
            {
                string tmp = s.substr(i, size2);
                sort(tmp.begin(), tmp.end());
                if (p.compare(tmp) == 0)
                {
                    res.push_back(i);
                    flag = true;
                }
                else
                {
                    flag = false;
                }
            }
        }
        return res;
    }
};
int main()
{
    vector<vector<int>> vn;
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    //v1.push_back(3);
    vn.push_back(v1);

    vector<int> v2;
    v2.push_back(8);
    v2.push_back(10);
    //v2.push_back(6);
    vn.push_back(v2);

    vector<int> v3;
    v3.push_back(2);
    v3.push_back(6);
    vn.push_back(v3);

    vector<int> v4;
    v4.push_back(15);
    v4.push_back(18);
    vn.push_back(v4);

    Solution s;
    vector<vector<int>> res = s.merge(vn);
    for (auto& i : res)
        cout << i[0] << " " << i[1] << endl;
    return 0;
}