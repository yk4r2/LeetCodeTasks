#include<iostream>
#include<vector>


using std::cout, std::endl, std::max, std::vector;


struct ListNode {
  int val;
  ListNode *next;
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* n) : val(x), next(n) {}
};


class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
  ListNode *slow = head, *fast = head;
  bool is_cycled = false;
  while (fast != nullptr && fast->next != nullptr) {
    fast = fast->next->next;
    slow = slow->next;
    if (fast == slow) {
    is_cycled = true;
    break;
    }
  }
  if (!is_cycled)
    return nullptr;

  slow = head;
  while (fast != slow) {
    fast = fast->next;
    slow = slow->next;
  }
  return fast;
  }
};


int main() {
  auto prehead = new ListNode(2);
  auto head = new ListNode(1, prehead);
  prehead->next = head;
  cout << Solution().detectCycle(head)->val;
  return 0;
}
