#include<iostream>
#include<string>
#include<stack>
#include<vector>
#include<map>

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
	ListNode* deleteDuplicates(ListNode* head) {
		map<int, int> m;
		ListNode* p = new ListNode();
		while (head != NULL) {
			map<int, int>::iterator it = m.find(head->val);
			if (it == m.end()) {
				m.insert(make_pair(head->val, 1));
			}
			else {
				(*it).second += 1;
			}
			head = head->next;
		}
		head = p;
		for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
			if ((*it).second == 1) {
				ListNode* list = new ListNode((*it).first);
				p->next = list;
				p = p->next;
			}
		}
		return head->next;
	}
};

int main() {
	Solution s;
	ListNode lst1(5);
	ListNode lst2(4, &lst1);
	ListNode lst3(4, &lst2);
	ListNode lst4(3, &lst3);
	ListNode lst5(3, &lst4);
	ListNode lst6(2, &lst5);
	ListNode lst7(1, &lst6);
	ListNode* result = s.deleteDuplicates(&lst7);
	while (result != NULL) {
		cout << result->val << "\t";
		result = result->next;
	}
	return 0;
}

#include<iostream>
//#include<string>
//#include<stack>
//#include<vector>
//#include<map>
//
//using namespace std;
//
//// Definition for singly-linked list.
//struct ListNode {
//	int val;
//	ListNode* next;
//	ListNode() : val(0), next(nullptr) {}
//	ListNode(int x) : val(x), next(nullptr) {}
//	ListNode(int x, ListNode* next) : val(x), next(next) {}
//};
//
//class Solution {
//public:
//	ListNode* deleteDuplicates(ListNode* head) {
//		map<int, int> m;
//		ListNode* p = new ListNode();
//		p->next = head;
//		ListNode* start = p;
//		while (p != NULL&&p->next!=NULL) {
//			int number = p->next->val;
//			ListNode* q = p->next->next;
//			while (q != NULL) {
//				if (q->val != number) {
//					break;
//				}
//				q = q->next;
//			}
//			if (q == p->next->next) {
//				p = p->next;
//			}
//			else {
//				p->next = q;
//			}
//		}
//		return start->next;
//	}
//};
//
//int main() {
//	Solution s;
//	ListNode lst1(5);
//	ListNode lst2(4, &lst1);
//	ListNode lst3(4, &lst2);
//	ListNode lst4(3, &lst3);
//	ListNode lst5(3, &lst4);
//	ListNode lst6(2, &lst5);
//	ListNode lst7(1, &lst6);
//	ListNode* result = s.deleteDuplicates(&lst7);
//	while (result != NULL) {
//		cout << result->val << "\t";
//		result = result->next;
//	}
//	return 0;
//}
