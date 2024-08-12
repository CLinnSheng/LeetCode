#include <bits/stdc++.h>
using namespace std;

class KthLargest {
public:
/*
Intuition: Can use a min heap and then pop until the kth largest element
then we continously pop until the size equal to k, so the toppest element will be the kth largeest element everytime
*/

    priority_queue<int, vector<int>, greater<int>> minHeap;
    int size;

    KthLargest(int k, vector<int>& nums) : size(k) {

        ios_base :: sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);   

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