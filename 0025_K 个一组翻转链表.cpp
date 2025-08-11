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

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* myfast = head;
        ListNode* myslow = head;
        ListNode* mylist = new ListNode(0, head);
        ListNode* res = mylist;
        int myk = 0;
        while (myfast != nullptr)
        {
            myk++;
            if (myk != k)
            {
                myfast = myfast->next;
            }
            else
            {
                myfast = myfast->next;
                myk = 0;
                ListNode* p1 = nullptr;

                //·´×ª
                while (myslow != myfast)
                {
                    ListNode* tmp = myslow->next;
                    myslow->next = p1;
                    p1 = myslow;
                    myslow = tmp;
                }
                mylist->next = p1;
                while (mylist->next != nullptr)
                {
                    mylist = mylist->next;
                }
            }
        }
        mylist->next = myslow;
        return res->next;
    }

};
int main()
{
    ListNode l5(5);
    ListNode l4(4, &l5);
    ListNode l3(3, &l4);
    ListNode l2(2, &l3);
    ListNode l1(1, &l2);
    Solution s;
    ListNode* res = s.reverseKGroup(&l1, 2);
    while (res != nullptr)
    {
        cout << res->val << endl;
        res = res->next;
    }

    return 0;
}