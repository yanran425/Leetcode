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

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* myhead = nullptr;
        while (head != nullptr)
        {
            ListNode* nextp = head->next;
            head->next = myhead;
            myhead = head;
            head = nextp;
        }
        return myhead;
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