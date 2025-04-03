#include <algorithm>
#include <vector>

/*
 * Value of a triplet:
 * (nums[i] - nums[j]) * nums[k]
 *
 * Goal: Return the maximum value over all triplets of indices (i, j, k)
 * where i < j < k. If all such triplet have a negative value return 0
 *
 * Intuition:
 * The naive way is just simply have a triple loop.
 * First loop trying every single index and then second loop to get those differences who are
 * greater than 0, then the final loop just for the multiplication.
 *
 * Can we optimize it?
 * A key observation is we need to find triplets such that it will have a value greater than 0.
 * So that means we simply just ignore the multiplication part. We need to find those values
 * where nums[i] > nums[j].
 * But the problem is how can we know any index greater than i is smaller than nums[i]?
 * The only way is prepopulate it because the information is in the future.
 * Besides that, we are trying to find the maximum value that means for the first part we need to find the greatest
 * difference which means the smallest nums[j] compare to nums[i] and then for the second part we need to find the
 * greaters nums[k] available such that k > j > i. So in simpler terms weneed to be greedy.
 * Instead of finding j, is much more easier to find i because if we lock j then for both i & k will be the greatest
 * value such the triplet values will be the greatest. So we can have 2 array, one that store the greatest value before
 * ith index and another store the greatest value afer ith index
 * Time Complexity: O(n)
 * */
class Solution
{
  public:
    long long maximumTripletValue(std::vector<int> &nums)
    {
        long long answer{};
        int len(nums.size());

        // Populate the prefixMax & suffixMax
        // prefixMax[i] means the largest nums value before nums[i]
        // suffixMax[i] means the largest value afer nums[i]
        std::vector<int> prefixMax(len, 0), suffixMax(len, 0);
        for (int i{1}; i < len; i++)
        {
            prefixMax[i] = std::max(prefixMax[i - 1], nums[i - 1]);
            suffixMax[len - 1 - i] = std::max(suffixMax[len - i], nums[len - i]);
        }

        for (int i{1}; i < len - 1; i++)
        {
            long long val{(long long)(prefixMax[i] - nums[i]) * suffixMax[i]};
            answer = std::max(answer, val);
        }
        return answer;
    }
};
