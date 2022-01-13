#include<iostream>
#include<vector>
#include<deque>


using std::cout, std::max, std::endl, std::vector, std::min, std::deque;


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  static ListNode(int x) : val(x), next(nullptr) {}
  static ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
 public:
  ListNode* sortLinkedList(ListNode* head) {
    ListNode *head_copy = head, *prev = head;
    head = head->next;
    while (head)
      if (head->val < 0) {
        prev->next = head->next;
        head->next = head_copy;
        head_copy = head;
        head = prev->next;
      } else {
        prev = head;
        head = head->next;
      }
    return head_copy;
  }
};


int main() {
  auto nextnext = ListNode(100);
  auto next = ListNode(-1, &nextnext);
  auto head = ListNode(-1, &next);
  cout << Solution().sortLinkedList(&head)->next->next->val;
}
