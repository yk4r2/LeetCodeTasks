#include<iostream>
#include<vector>


using std::vector, std::cout, std::endl, std::string, std::max;


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
 public:
  ListNode* merge(ListNode* head1, ListNode* head2) {
    ListNode dummy_head(0);
    ListNode* pointer = &dummy_head;
    while (head1 && head2) {
      if (head1->val <= head2->val) {
        pointer->next = head1;
        head1 = head1->next;
      } else {
        pointer->next = head2;
        head2 = head2->next;
      }
      pointer = pointer->next;
    }
    pointer->next = head1 ? head1 : head2;
    return dummy_head.next;
  }

  ListNode* getMid(ListNode* head) {
    ListNode* mid_pointer = nullptr;
    while (head && head->next) {
      mid_pointer = mid_pointer == nullptr ? head : mid_pointer->next;
      head = head->next->next;
    }
    ListNode* mid = mid_pointer->next;
    mid_pointer->next = nullptr;
    return mid;
  }

  ListNode* sortList(ListNode* head) {
    if (!head || !head->next)
      return head;
    ListNode* mid = getMid(head);
    ListNode* left = sortList(head);
    ListNode* right = sortList(mid);
    return merge(left, right);
  }
};


int main() {
  auto* head = new ListNode(4);
  head->next = new ListNode(2);
  head->next->next = new ListNode(1);
  head->next->next->next = new ListNode(3);
  head = Solution().sortList(head);
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
  return 0;
}

