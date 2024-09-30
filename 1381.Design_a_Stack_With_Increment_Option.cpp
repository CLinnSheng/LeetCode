// Time Complexity: For push and pop is O(1) and increment is O(K)
// Space Complexity: O(n)
class CustomStack {
public:
  std::deque<int> stack;
  std::size_t capacity;
  CustomStack(int maxSize) : capacity{static_cast<std::size_t>(maxSize)} {}

  void push(int x) {
    if (stack.size() == capacity)
      return;
    stack.emplace_back(x);
  }

  int pop() {
    if (stack.empty())
      return -1;
    auto top = stack.back();
    stack.pop_back();
    return top;
  }

  void increment(int k, int val) {
    auto size = (k > stack.size()) ? stack.size() : k;
    std::deque<int> temp_stack;
    for (int i = 0; i < size; i++) {
      auto top = stack.front();
      stack.pop_front();
      temp_stack.emplace_front(top);
    }

    for (const auto &i : temp_stack)
      stack.emplace_front(i + val);
  }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */
