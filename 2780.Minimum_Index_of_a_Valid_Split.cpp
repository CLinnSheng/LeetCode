#include <unordered_map>
#include <vector>

/*
 * An element x is dominant if more than half the element of array haev a value of x.
 * Given an array with only one dominant element
 * Split the array at index i into 2 arrays, and the split only valid if:
 * i. 0 <= i < n - 1
 * ii. nums[0 .. , i] & nums[i + 1 .., n-1] have the same dominant element
 *
 * Intuitoin:
 * Since we need to find the dominant element, means that we need to keep track of the frequency of the value
 * So the data structure we can use is a hash map
 * The brute force way is to iterate through the array and then iterate through the left part and ifnd the dominant and
 * the same to the right part This is not efficient, the time complexity is O(n^2)
 *
 * Is there any way we can do so that no need to iterate through the hash map everytime?
 * We can populate the hashmap first. --> right half
 * So everytime when iterate thourgh the array, we will add the current index to the left and remove it form the right
 * But how do we know whether is it a valid array or not?
 *
 * For the left part is easy, we just need a variable to store the last dominant element. So every time we insert a new
 * element, we need to check whether it is greater than the last dominant element or not if yes --> then check n * 2 >
 * size else --> check prev dominant element n * 2 > size
 * so we can overcome the edge cases where everytime insert a new element, so wont be any dominant element inside
 *
 * How about the right half part?
 * Before dive right in, i notice another observatoin where the dominant on the left and dominant on the right should be
 * the dominant elmeent on the entire array
 * so we just need to check when the left part dominant equal to the dominant val of the entire array and for the right
 * part it still remain the dominant element
 *
 * For left part, no need to check the dominant everytime inserting a new element. What we want to know is just when is
 * the time that the dominant left is equal to the dominat of entire array and also equal to dominant right
 * Time Complexity: O(n)
 * * */
class Solution
{
  public:
    int minimumIndex(std::vector<int> &nums)
    {
        int answer{-1}, size(nums.size());
        std::unordered_map<int, int> freq;

        // find the dominant element first
        int dominantVal, dominantFreq{};
        for (const auto &num : nums)
            freq[num]++;

        for (const auto &[val, f] : freq)
            if (f > dominantFreq)
            {
                dominantFreq = f;
                dominantVal = val;
            }

        if (freq[dominantVal] * 2 <= size)
            return -1;

        // 2. Iterate through the array
        std::unordered_map<int, int> leftFreq;
        for (int index{}; index < size; index++)
        {
            // insert into the left
            leftFreq[nums[index]]++;
            // check the new insert element got cause changes of the dominant left
            // only adding the existing element will change the dominant and if add new element will cause no dominant
            // in the array
            // for the left we dont really need to track whats the dominant every single time

            // remove from the right
            freq[nums[index]]--;

            if (leftFreq[dominantVal] * 2 > (index + 1) && freq[dominantVal] * 2 > (size - (index + 1)))
                return index;
        }

        return answer;
    }
};
;
