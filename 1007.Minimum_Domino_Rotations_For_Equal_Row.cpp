#include <climits>
#include <unordered_map>
#include <vector>

/*
 * tops[i] & bottoms[i] represent the top and bottom halves of the ith domino.
 * Rotate the ith domino, so that tops[i] & bottoms[i] swap values.
 *
 * Goal: Return the minimum number of rotations so that all values in the top or bottom are the same
 * Otherwise return -1;
 *
 * Intuition:
 * Since we need to make it all the same value in either row.
 * We need information of the domino at each ith position of both top and row in order to know whether is it possible to
 * make it all the same or not. The minimum for all the row to be the same is the freq of the value must be at least
 * equal or greater than the length of the row
 * Time Complexity: O(n)
 * */
class Solution
{

  public:
    int minDominoRotations(std::vector<int> &tops, std::vector<int> &bottoms)
    {
        int answer{INT_MAX};
        std::unordered_map<int, int> freq;

        for (int i{}; i < tops.size(); i++)
        {
            freq[tops[i]]++;
            freq[bottoms[i]]++;
        }

        bool canMake{};
        for (const auto &[val, cnt] : freq)
        {
            if (cnt < tops.size())
                continue;

            bool canMake{true};
            int botflip{}, topflip{};
            for (int i{}; i < tops.size(); i++)
            {
                if (tops[i] != val && bottoms[i] != val)
                {
                    canMake = false;
                    break;
                }

                if (tops[i] != val)
                    topflip++;
                if (bottoms[i] != val)
                    botflip++;
            }

            if (canMake)
                answer = std::min(answer, std::min(topflip, botflip));
        }

        return answer != INT_MAX ? answer : -1;
    }
};
