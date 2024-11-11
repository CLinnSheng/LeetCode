#include <cmath>
#include <cstddef>
#include <functional>
#include <vector>

/*
 * Given an array and perform the following operation
 * Pick an index i that you havent picked before and pick a prime p strictly
 * less than nums[i], then subtract p from it Goal: Return true if u can make
 * the array in ascending order using the above operation
 *
 * Intuition: We can go greedy by iterate through the array and find the prime
 * number that is closest and less than nums[i] Time Complexity: O(n * m *
 * sqrt(m)) Space Complexity: O(1)
 *
 * Actually we can further optimize this, if u observed we actually keep
 * computing the same primeNumber multiple time. We can optimize it by
 * precompute it and how do we determine the range of primeNumber? Simply take
 * the compute from the largest element in the array to 2
 * */
class Solution {
public:
  bool primeSubOperation(std::vector<int> &nums) {

    std::size_t size{nums.size()};
    if (size == 1)
      return true;

    std::function<bool(const int &)> isPrime = [](const int &n) {
      for (int i{2}; i <= std::sqrt(n); i++)
        if (n % i == 0)
          return false;
      return true;
    };

    std::vector<int> primeNumbers(2, 0);
    for (int i{2}; i <= *std::max_element(nums.begin(), nums.end()); i++)
      primeNumbers.emplace_back(isPrime(i) ? i : primeNumbers.back());

    int prevNumber{};
    for (const auto &num : nums) {
      // upperbound for the maximum prime number we want to get
      // subtract from prevNmber because we dont want it to be the same as the
      // prevNumber
      int upperBound{num - prevNumber};

      // finding the possible maximum primeNumber
      int largestPrimeNumber{upperBound > 0 ? primeNumbers[upperBound - 1] : 0};
      if (num - largestPrimeNumber <= prevNumber)
        return false;

      prevNumber = std::move(num - largestPrimeNumber);
    }
    return true;
  }
};
