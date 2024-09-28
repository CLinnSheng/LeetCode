/*
 * Goal: Design a circular deque
 * Intuition: Since every single element is kinda related to one another or in
 * another word they are link so we can think of using double linkedlist to
 * implement it Since we want to able to getFront and getRear, insertFront &
 * inserLast, deleteFront & deleteLast. We need a pointer pointed to it so we
 * can acces it in O(1)
 * */

#include <cstddef>
#include <iterator>
struct LinkedList {
  int val_node;
  LinkedList *next;
  LinkedList *prev;

  LinkedList(int val) noexcept : val_node{val}, next{nullptr}, prev{nullptr} {}
};

class MyCircularDeque {
private:
  LinkedList *head;
  LinkedList *tail;
  int capacity;
  std::size_t size;

public:
  MyCircularDeque(int k) noexcept
      : head{nullptr}, tail{nullptr}, capacity{k}, size{0} {}

  bool insertFront(int value) {
    // handle empty linkedlist
    if (size == 0) {
      head = new LinkedList(value);
      tail = head;
    } else if (size == capacity)
      return false;
    else {
      LinkedList *temp = new LinkedList(value);
      temp->next = head;
      head->prev = temp;
      head = temp;
    }
    size++;
    return true;
  }

  bool insertLast(int value) {
    if (size == 0) {
      tail = new LinkedList(value);
      head = tail;
    } else if (size == capacity)
      return false;
    else {
      LinkedList *temp = new LinkedList(value);
      tail->next = temp;
      temp->prev = tail;
      tail = temp;
    }
    size++;
    return true;
  }

  bool deleteFront() {
    if (size == 0)
      return false;
    else if (size == 1)
      head = tail = nullptr;
    else {
      LinkedList *temp = head;
      head = head->next;
      delete temp;
      head->prev = nullptr;
    }
    size--;
    return true;
  }

  bool deleteLast() {
    if (size == 0)
      return false;
    else if (size == 1)
      tail = head = nullptr;
    else {
      LinkedList *temp = tail;
      tail = tail->prev;
      delete temp;
      tail->next = nullptr;
    }
    size--;
    return true;
  }

  int getFront() { return head ? head->val_node : -1; }

  int getRear() { return tail ? tail->val_node : -1; }

  bool isEmpty() { return size == 0; }

  bool isFull() { return size == capacity; }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */
