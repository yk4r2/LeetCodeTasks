#include<iostream>
#include<vector>
#include<unordered_map>


using std::cout, std::endl, std::max, std::vector, std::unordered_map;


class DoublyLinkedNode {
 public:
  int key, val;
  DoublyLinkedNode *next, *prev;
  DoublyLinkedNode(int k, int v) {
    key = k;
    val = v;
    next = nullptr;
    prev = nullptr;
  }
};

class DoublyLinkedList {
 public:
  DoublyLinkedNode* first;
  DoublyLinkedNode* last;
  DoublyLinkedList() {
    first = last = nullptr;
  }

  void pushBack(DoublyLinkedNode* new_node) {
    if (!first) {
      first = last = new_node;
    } else {
      last->next = new_node;
      new_node->prev = last;
      last = new_node;
      new_node->next = nullptr;
    }
  }

  void removeHead() {
    if (first) {
      DoublyLinkedNode* tmp = first;
      if (first == last) {
        first = last = nullptr;
      } else {
        first = first->next;
        first->prev = nullptr;
      }
      delete tmp;
    }
  }

  DoublyLinkedNode* removeNode(DoublyLinkedNode* node) {
    if (node == first && node == last) {
      first = nullptr;
      last = nullptr;
    } else if (node->key == first->key) {
      first = first->next;
      if (first)
        first->prev = nullptr;
    } else if (node->key == last->key) {
      last = last->prev;
      last->next = nullptr;
    } else {
      if (node->next)
        node->next->prev = node->prev;
      if (node->prev)
        node->prev->next = node->next;
    }
    return node;
  }
};

class LRUCache {
 private:
  unordered_map<int, DoublyLinkedNode*> hashmap;
  DoublyLinkedList* dll;
  int max_capacity;
 public:
  LRUCache(int capacity) {
    max_capacity = capacity;
    dll = new DoublyLinkedList();
  }

  int get(int key) {
    int result = INT_MAX;
    if (hashmap.count(key)) {
      DoublyLinkedNode* node = hashmap[key];
      result = node->val;
      if (node != dll->last) {
        node = dll->removeNode(node);
        dll->pushBack(node);
        hashmap[key] = dll->last;
      }
    } else {
      result = -1;
    }
    return result;
  }

  void put(int key, int value) {
    if (hashmap.count(key)) {
      DoublyLinkedNode* node = hashmap[key];
      delete dll->removeNode(node);
      hashmap.erase(key);
    } else {
      if (hashmap.size() == max_capacity) {
        int del_key = dll->first->key;
        hashmap.erase(del_key);
        dll->removeHead();
      }
    }
    auto* node = new DoublyLinkedNode(key, value);
    hashmap[key] = node;
    dll->pushBack(node);
  }
};



int main() {
  LRUCache* cache = new LRUCache(2);
  cache->put(1, 1);
  cache->put(2, 2);
  cout << cache->get(1) << endl;
  cache->put(3, 3);
  cout << cache->get(2) << endl;
  cache->put(4, 4);
  cout << cache->get(1) << endl;
  cout << cache->get(3) << endl;
  cout << cache->get(4) << endl;
  return 0;
}
