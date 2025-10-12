#include <algorithm>
#include <unordered_map>
#include <vector>

/*
 * Given an array power where each element represent the damage of a spell. Multiple spells can have the same damage
 * value If a magician decides to cast a spell with a damage of power[i], it cannot cast any spell damage of power[i]
 * -2, power[i] - 1, power[i] + 1, power[i] + 2 NOTE: Each spell can be only cast once
 *
 *
 * Goal: Return the maximum possible total damage that a magician can cast
 *
 * Intuition:
 * The only concern is that the damage of the spells we already taken, need to take note that cannot take power[i] +/-
 * 1/2 So ideally we will take whatever the current damage has (hash map) then iterate through the array to find the
 * next legit damage we can take (sort the array) can use dp to cache previous taken damage at index i where dp[i]
 * maximum total damage we can get up to index i
 * Time Complexity: O(nlgn)
 * */

class Solution
{
  public:
    long long maximumTotalDamage(std::vector<int> &power)
    {
        std::unordered_map<int, int> damageFreq;
        for (const auto p : power)
            damageFreq[p]++;

        std::vector<long long> sortedDamage;
        for (const auto &[damage, freq] : damageFreq)
            sortedDamage.emplace_back(damage);
        std::sort(sortedDamage.begin(), sortedDamage.end());

        int n(sortedDamage.size());
        std::vector<long long> dp(n);
        dp[0] = damageFreq[sortedDamage[0]] * sortedDamage[0];

        for (int i{1}; i < n; i++)
        {
            long long damageTaken{sortedDamage[i] * damageFreq[sortedDamage[i]]};
            // Find the previous valid damage we can take which is sortedDamage[i] - 3
            int preValidDamage = std::upper_bound(sortedDamage.begin(), sortedDamage.end(), sortedDamage[i] - 3) -
                                 sortedDamage.begin() - 1;

            damageTaken += preValidDamage >= 0 ? dp[preValidDamage] : 0;
            dp[i] = std::max(dp[i - 1], damageTaken);
        }
        return dp[n - 1];
    }
};
