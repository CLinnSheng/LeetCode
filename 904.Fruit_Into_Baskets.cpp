/*
 * fruits[i] -> type of fruit the ith tree produces
 * Rule:
 * - 2 Baskets. Each basket hold a single type of fruit. No limit how much fruit each basket can hold
 * - Starting from any tree of choice. Pick exactly one fruit from every tree.
 * - Once reach a tree with fruit that cannot fit in your basket, then stop
 * Goal: Collect as much fruit as possible.
 *
 * Intuition:
 * We must pick wisely from where to start because once we reach a tree with fruit that cannot fit into the basket then
 * we have to stop We can use a sliding window to hold window of 2 type of fruit only, once reach 3 we have to remove
 * from the left until only left 2
 * */
#include <unordered_map>
#include <vector>
class Solution
{
  public:
    int totalFruit(std::vector<int> &fruits)
    {
        int left{}, right{};
        std::unordered_map<int, int> fruit;
        int answer{}, currCnt{};

        while (right < fruits.size())
        {
            currCnt++;
            fruit[fruits[right]]++;

            while (left < right && fruit.size() > 2)
            {
                fruit[fruits[left]]--;
                if (fruit[fruits[left]] == 0)
                {
                    fruit.erase(fruits[left]);
                    currCnt = 0;

                    for (const auto &[_, freq] : fruit)
                        currCnt += freq;
                }

                left++;
            }

            answer = std::max(answer, currCnt);
            right++;
        }

        return answer;
    }
};
