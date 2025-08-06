#include<iostream>
#include<vector>

using namespace std;


// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int flag = 0;
		ListNode list;
		ListNode* p = &list;
		while (l1 != NULL && l2 != NULL) {
			int sum = l1->val + l2->val + flag;
			if (sum >= 10) {
				flag = 1;
			}
			else {
				flag = 0;
			}
			ListNode* lst = new ListNode(sum % 10);
			p->next = lst;
			p = lst;
			l1 = l1->next;
			l2 = l2->next;
		}
		while (l1 != NULL) {
			int sum = l1->val + flag;
			if (sum >= 10) {
				flag = 1;
			}
			else {
				flag = 0;
			}
			ListNode* lst = new ListNode(sum % 10);
			p->next = lst;
			p = lst;
			l1 = l1->next;
		}
		while (l2 != NULL) {
			int sum = l2->val + flag;
			if (sum >= 10) {
				flag = 1;
			}
			else {
				flag = 0;
			}
			ListNode* lst = new ListNode(sum % 10);
			p->next = lst;
			p = lst;
			l2 = l2->next;
		}
		if (flag == 1) {
			ListNode* lst = new ListNode(1);
			p->next = lst;
		}
		return list.next;
	}
};

int main() {
	ListNode lst1(3);
	ListNode lst2(4, &lst1);
	ListNode l1(2, &lst2);
	ListNode lst3(4);
	ListNode lst4(6, &lst3);
	ListNode l2(5, &lst4);
	Solution s;
	ListNode* result = s.addTwoNumbers(&l1, &l2);
	while (result != NULL) {
		cout << result->val << "\t";
		result = result->next;
	}
	cout << endl;
	return 0;
}
