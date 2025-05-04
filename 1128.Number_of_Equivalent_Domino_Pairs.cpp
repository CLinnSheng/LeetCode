#include <unordered_map>
#include <vector>

/*
 * A dominioes[i] = [a,b] is equivalent to dominoes[j] = [c,d]
 * if and only if either (a==c && b==d) or (a==d && b==c) which means flip it and equal to another domino
 *
 * Goal: Return the number of pairs (i, j) which 0 <= i,j < dominoes.length and dominoes[i] is equivalent to dominoes[j]
 *
 * Intuition:
 * The brute force will just simply loop the array twice but this costs O(n^2)
 *
 * Since we want to find the equivalent pair, so we need to keep track of the domino we have visited.
 * The only way to do is use a hash map.
 * Since we cannot save a tuple as a key in a hash map in cpp.
 * Since the value of dominoes[i][j] is 1 <= x <= 9
 * We can just simply make our own key.
 * Time Comeplxity: O(n)
 *
 * */
class Solution
{
  public:
    int numEquivDominoPairs(std::vector<std::vector<int>> &dominoes)
    {
        int answer{};

        std::unordered_map<int, int> dominoCnt;

        for (const auto &domino : dominoes)
        {
            int val = domino[0] > domino[1] ? domino[0] * 10 + domino[1] : domino[1] * 10 + domino[0];
            answer += dominoCnt[val];

            dominoCnt[val]++;
        }

        return answer;
    }
};
