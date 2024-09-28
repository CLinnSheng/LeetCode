#include <cstdint>
struct Node {
  std::int32_t val;
  Node *nxt;

  Node(int val_) noexcept : val{val_}, nxt{nullptr} {}
};

class MyLinkedList {
public:
  Node *root;
  std::size_t size;
  MyLinkedList() noexcept : root{nullptr}, size{0} {}

  int get(int index) {
    if (index < 0 || index >= size)
      return -1;
    Node *temp = root;
    for (int i = 0; i < index; i++)
      temp = temp->nxt;
    return temp->val;
  }

  void addAtHead(int val) { this->addAtIndex(0, val); }

  void addAtTail(int val) { this->addAtIndex(size, val); }

  void addAtIndex(int index, int val) {
    if (index < 0 || index > size)
      return;
    Node *temp = root;
    Node *new_node = new Node(val);

    // find the node before the index
    if (index == 0) {
      new_node->nxt = temp;
      root = new_node;
    } else {
      for (int i = 0; i < index - 1; i++)
        temp = temp->nxt;

      Node *curr = temp->nxt;
      temp->nxt = new_node;
      new_node->nxt = curr;
    }

    size++;
  }

  void deleteAtIndex(int index) {
    if (index < 0 || index >= size || size == 0 || !root)
      return;

    Node *temp = root;
    if (index == 0) {
      root = root->nxt;
      delete temp;
    } else {
      for (int i = 0; i < index - 1; i++)
        temp = temp->nxt;

      Node *curr = temp->nxt;

      temp->nxt = curr->nxt;
      delete curr;
    }

    size--;
  }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
