#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
class Solution {
public:
    vector<int> v;
    void digui(vector<vector<int>>& matrix)
    {
        if (matrix.size() == 0)
            return;
        else if (matrix.size() == 1)
        {
            for (auto i : matrix[0])
            {
                v.emplace_back(i);
            }
            return;
        }
        else
        {
            auto it = matrix.begin();
            for (auto i : (*it))
            {
                v.emplace_back(i);
            }
            matrix.erase(it);
            if (matrix.size() == 0)
                return;

            for (auto& i : matrix)
            {
                v.push_back(i.at(i.size() - 1));
                i.erase(i.end() - 1);
            }
            it = matrix.begin();
            while (it != matrix.end())
            {
                if ((*it).size() == 0)
                    it = matrix.erase(it);
                else
                    it++;
            }
            if (matrix.size() == 0)
                return;

            it = matrix.end() - 1;
            for (int i = int((*it).size()) - 1; i >= 0; i--)
            {
                v.push_back((*it)[i]);
            }
            matrix.erase(it);
            if (matrix.size() == 0)
                return;

            for (int i = int(matrix.size()) - 1; i >= 0; i--)
            {
                v.push_back(matrix[i].at(0));
                matrix[i].erase(matrix[i].begin());
            }
            it = matrix.begin();
            while (it != matrix.end())
            {
                if ((*it).size() == 0)
                    it = matrix.erase(it);
                else
                    it++;
            }
            if (matrix.size() == 0)
                return;
            digui(matrix);
        }
    }
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        digui(matrix);
        return this->v;
    }
};
int main()
{
    vector<vector<int>> vn;
    vector<int> v1;
    v1.push_back(1);
    //v1.push_back(2);
    //v1.push_back(3);
    vn.push_back(v1);

    vector<int> v2;
    v2.push_back(4);
    //v2.push_back(5);
    //v2.push_back(6);
    vn.push_back(v2);

    vector<int> v3;
    v3.push_back(7);
    //v3.push_back(8);
    //v3.push_back(9);
    vn.push_back(v3);
    Solution s;
    vector<int> res = s.spiralOrder(vn);
    for (auto i : res)
        cout << i << endl;
    return 0;
}