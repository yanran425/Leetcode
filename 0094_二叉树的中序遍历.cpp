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
    ListNode(int x) : val(x), next(NULL) {}
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
    vector<int> res;
    void digui(TreeNode* root)
    {
        if (root)
        {
            digui(root->left);
            res.push_back(root->val);
            digui(root->right);
        }

    }
    vector<int> inorderTraversal(TreeNode* root) {
        digui(root);
        return res;
    }

};
int main()
{
    vector<int> v1;
    v1.push_back(1);
    v1.push_back(3);
    v1.push_back(2);

    Solution s;
    s.nextPermutation(v1);
    for (auto& i : v1)
        cout << i << endl;
    return 0;
}