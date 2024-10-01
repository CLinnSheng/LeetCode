/*
Goal: Check if sum of each pairs is dvisible by k
Intuition: Using naive approach we will able to do so, but that is very costly
which is O(n^2) We need to find way to reduce it to O(n) We can make use of
modulo arithmetic Let ai and aj from the array of elements ai and aj forms pairs
that is divisible by k if and only if ( (ai%k) + (aj%k) % k ) == 0 in another
way it means that let ai % k = modi therefore (modi + (k - modi) % k) == 0 so
the freq of modi and k - modi must be the same inorder for it to equal to 0

Time Complexity: O(n)
Space Complexity: O(n)
*/
#include <ios>
#include <ios_base>
#include <vector>

class Solution {
public:
  bool canArrange(std::vector<int> &arr, int k) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // keep count of the the remainder
    std::unordered_map<int, int> freqCount;
    for (const auto &i : arr)
      // to handle negative value
      freqCount[((i % k) + k) % k]++;

    for (const auto &[remainder, cnt] : freqCount) {
      // handle 0 remainder case
      if (remainder == 0)
        return freqCount[remainder] % 2 ? false : true;

      // the cnt has to be even to able to divisible by k
      if (freqCount[k - remainder] != cnt)
        return false;
    }
    return true;
  }
};
