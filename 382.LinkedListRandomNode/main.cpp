#include<iostream>


using std::cout, std::endl;


struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  explicit ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
 private:
  int len = 0;
  ListNode* llist;
 public:
  explicit Solution(ListNode* head) {
  llist = head;
  ListNode* ptr = head;
  while (ptr) {
    len++;
    ptr = ptr->next;
  }
  }

  int getRandom() {
  int our_index = rand() % len;
  ListNode* ptr = llist;
  for (int i = 0; i < our_index; ++i)
    ptr = ptr->next;
  return ptr->val;
  }
};


int main() {
  srand(42);
  auto tail = ListNode(2);
  auto pretail = ListNode(3, &tail);
  auto head = ListNode(1, &pretail);
  cout << Solution(&head).getRandom();
}
