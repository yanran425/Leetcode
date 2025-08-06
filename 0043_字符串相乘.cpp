#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
        {
            return "0";
        }
        if (num1 == "1")
        {
            return num2;
        }
        if (num2 == "1")
        {
            return num1;
        }
        int length1 = num1.size();
        int length2 = num2.size();
        vector<int> v1;

        for (int i = 0; i < length2; i++)
        {
            int n2 = num2[length2 - i - 1] - '0';
            vector<int> v2(i, 0);
            int jinwei = 0;
            for (int j = 0; j < length1; j++)
            {
                int n1 = num1[length1 - j - 1] - '0';
                int n3 = n1 * n2 + jinwei;
                int yu = n3 % 10;
                v2.push_back(yu);
                jinwei = n3 / 10;
            }
            if (jinwei)
            {
                v2.push_back(jinwei);
            }
            vector<int> v3;
            int lengthv1 = v1.size();
            int lengthv2 = v2.size();
            jinwei = 0;
            int pos1 = 0;
            int pos2 = 0;
            while (pos1 < lengthv1 || pos2 < lengthv2 || jinwei != 0)
            {
                int x = pos1 < lengthv1 ? v1[pos1] : 0;
                int y = pos2 < lengthv2 ? v2[pos2] : 0;
                int z = x + y + jinwei;
                v3.push_back(z % 10);
                jinwei = z / 10;
                pos1++;
                pos2++;
            }
            v1 = v3;

        }
        string res = "";
        int length = v1.size();
        for (int i = length - 1; i >= 0; i--)
        {
            res.push_back(v1[i] + '0');
        }
        return res;

    }
};

int main()
{
    string s1 = "12";
    string s2 = "10";
    Solution s;
    string s3 = s.multiply(s1, s2);
    cout << s3 << endl;
    return 0;

}