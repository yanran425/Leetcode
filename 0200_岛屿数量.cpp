#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<map>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void digui(vector<vector<char>>& grid, int row, int col, int i, int j)
    {
        if (i > 0)
        {
            if (grid[i - 1][j] == '1')
            {
                grid[i - 1][j] = '2';
                digui(grid, row, col, i - 1, j);
            }
        }
        if (i < row - 1)
        {
            if (grid[i + 1][j] == '1')
            {
                grid[i + 1][j] = '2';
                digui(grid, row, col, i + 1, j);
            }
        }
        if (j > 0)
        {
            if (grid[i][j - 1] == '1')
            {
                grid[i][j - 1] = '2';
                digui(grid, row, col, i, j - 1);
            }
        }
        if (j < col - 1)
        {
            if (grid[i][j + 1] == '1')
            {
                grid[i][j + 1] = '2';
                digui(grid, row, col, i, j + 1);
            }
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (grid[i][j] == '1')
                {
                    grid[i][j] = '2';
                    res++;
                    digui(grid, row, col, i, j);
                }
            }
        }
        return res;
    }
};

int main()
{
    vector<vector<char>> grids;
    vector<char> v = { '1','1','1','1','0' };
    grids.push_back(v);
    v = { '1','1','0','1','0' };
    grids.push_back(v);
    v = { '1','1','0','0','0' };
    grids.push_back(v);
    v = { '0','0','0','0','0' };
    grids.push_back(v);

    Solution s;
    int res = s.numIslands(grids);
    cout << res << endl;

    return 0;
}