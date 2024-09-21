/*
Goal: Maintains a stream of test scores and continously return the kth highest
test score Intuition: Since need to continously return the kth highest test
score A data structure that always has the kth highest test score on the top of
data structure
--> minHeap with size of k, so the top will be the kth highest test score

Time Complexity: O(mlgk + nlgk) first we buld the heap and then add n times
Space Complexity: O(k)
*/
class KthLargest {
public:
  std::priority_queue<int, std::vector<int>, greater<int>> minHeap;
  int size;
  KthLargest(int k, vector<int> &nums) : size(k) {
    for (const auto &num : nums)
      minHeap.emplace(num);
  }

  int add(int val) {
    minHeap.emplace(val);

    while (minHeap.size() > size)
      minHeap.pop();

    return minHeap.top();
  }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
