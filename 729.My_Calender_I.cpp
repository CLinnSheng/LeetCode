/*
 * Goal: add an event so that will not cause a double booking
 * Condition: The event is [start, end)
 * for example the fist event is at [20,30) the next is valid if [30,35)
 *
 * Intuition: We need to find an event from the list that is most close to the
 * event want to insert Lets say we find the event that has equal or greater
 * than the event want to insert then we check will they be overllaping we also
 * need to handle cases where we dont have event hat is greater or equal than
 * the event want to isnert this condition where event might intersect with the
 * right half of the eixsting event. So we need to retrieve the past event and
 * check whether did they overlapp
 *
 * Tiem Complexity: O(nlgn) because we will be using a dat structure that is
 * sorted Space Complexity: O(n)
 * */
#include <iterator>
#include <set>
#include <utility>

// class MyCalendar {
// public:
//   std::set<std::pair<int, int>> event_list;

//   MyCalendar() {}

//   bool book(int start, int end) {

//     if (event_list.empty()) {
//       event_list.emplace(start, end);
//       return true;
//     }

//     // find the event that is equal or greater than the event we want to
//     insert auto it = event_list.lower_bound({start, end});

//     if (it != event_list.end() && end > it->first)
//       return false;

//     if (it != event_list.begin()) {
//       it = std::prev(it);
//       if (it->second > start)
//         return false;
//     }

//     event_list.emplace({start, end});
//     return true;
//   }
// };

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 *
 */

/*
 * Another way of is creating a custom BST tree
 * this will reduce the time complexity to O(lgn) which is the hegiht of the
 * tree Design of the tree: the event will go to the left node if the insert
 * event of the end is lesser than the start of the root similarly if the insert
 * event start is greater or equal to the end of the root insert to the right
 */

class Tree {
private:
  std::pair<int, int> node;
  Tree *left;
  Tree *right;

public:
  Tree(int start, int end) {
    node = std::make_pair(start, end);
    left = nullptr;
    right = nullptr;
  }

  bool insert(Tree *event_node, int start, int end) {
    while (true) {
      if (start >= event_node->node.second) {
        if (event_node->right == nullptr) {
          event_node->right = new Tree(start, end);
          return true;
        }
        event_node = event_node->right;
      }

      else if (end <= event_node->node.first) {
        if (event_node->left == nullptr) {
          event_node->left = new Tree(start, end);
          return true;
        }
        event_node = event_node->left;
      } else
        return false;
    }
  }
};

class MyCalendar {
  Tree *root;

public:
  MyCalendar() { root = nullptr; }

  bool book(int start, int end) {
    if (root == nullptr) {
      root = new Tree(start, end);
      return true;
    }

    return root->insert(root, start, end);
  }
};
