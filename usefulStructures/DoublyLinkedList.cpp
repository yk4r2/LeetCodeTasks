struct DoublyLinkedList {
  int val;
  DoublyLinkedList *next;
  DoublyLinkedList *prev;
  DoublyLinkedList() : val(0), next(nullptr), prev{nullptr} {}
  explicit DoublyLinkedList(int x) : val(x), next(nullptr), prev(nullptr) {}
  DoublyLinkedList(int x, DoublyLinkedList *prev) : val(x), next(nullptr), prev(prev) {}
  DoublyLinkedList(int x, DoublyLinkedList *next, DoublyLinkedList *prev) : val(x), next(next), prev(prev) {}
};
