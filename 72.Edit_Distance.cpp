#include <string>
#include <vector>
/*
 * So at every index we have 3 type of actions:
 * 1. Insert a character
 * 2. Delete a character
 * 3. Replace a character
 *
 * So we can get the edit distance by counting the number of each type of action.
 *
 * Goal: Return the minimum number of operations required to convert word1 to word2
 *
 * Intuition:
 * So at every index we have 3 type of action.
 * What we can do from brute force is try out all possible action at each index if the character is not equal
 * Time Complexity will be O(3^n) where n is the length of the shorter string
 *
 * From this brute force approach we can see we have being doing repetitive work.
 * We can optimize this by use cache
 * The thing that we pass down the recursive function is the 2 index, so the array will be 2d
 * Time Complexity will be reduced to O(n^2)
 * */
class Solution
{
  private:
    int dfs(std::string word1, std::string word2, int index1, int index2, std::vector<std::vector<int>> &cache)
    {
        if (cache[index1][index2] != -1)
        {
            return cache[index1][index2];
        }
        // Base Case where word1 is finish
        if (index1 == word1.size())
        {
            return cache[index1][index2] = word2.size() - index2;
        }

        // Base Case where word2 is finish
        if (index2 == word2.size())
        {
            return cache[index1][index2] = word1.size() - index1;
        }

        // If same character then no need to do anything
        if (word1[index1] == word2[index2])
            return cache[index1][index2] = dfs(word1, word2, index1 + 1, index2 + 1, cache);
        else
        {
            // If not same character then we can do 3 type of action
            // 1. Insert a character
            // 2. Delete a character
            // 3. Replace a character
            // then get the min of these 3 type of action
            return cache[index1][index2] =
                       std::min(dfs(word1, word2, index1 + 1, index2, cache),                 // Delete
                                std::min(dfs(word1, word2, index1, index2 + 1, cache),        // Insert
                                         dfs(word1, word2, index1 + 1, index2 + 1, cache))) + // Replace character
                       1;
        }
    }

  public:
    int minDistance(std::string word1, std::string word2)
    {
        // One size larger because of the base case
        std::vector<std::vector<int>> cache(word1.size() + 1, std::vector<int>(word2.size() + 1, -1));
        return dfs(word1, word2, 0, 0, cache);
    }
};
