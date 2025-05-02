#include <string>
#include <vector>
/*
 * Given a string of dominioes
 * dominoes[i] = 'L' push to the left
 * dominoes[i] = 'R' push to the right
 * dominoes[i] = '.' hsa not been pushed
 *
 * Goal: Return a string representing the final state
 *
 * Intuition:
 * Key observations is a domino will be still if there is an equal amount of force from both sides or not being pushed
 * at all. The first instuition is used stack but cannot because we need information from the left and the right. We
 * need a prefix to track the force at every single index from the left to the right and from the right to the left.
 * from the left to the right we will track whats the left force?
 * from the right to the left whats the right force.
 * Another importnat thing is the force doesnt add on for example two right dominioes is also equivalent to 1, so for
 * every index we need to know whether is it left or right ttilt
 * For '.' we need to determine which left or right force is greater by means which force is nearer.
 * Time Complexity: O(n)
 *
 * */

class Solution
{
  public:
    std::string pushDominoes(std::string dominoes)
    {
        int n(dominoes.size());
        std::vector<int> forces(n, 0);

        // left to right --> right
        int force{};
        for (int i{}; i < n; i++)
        {
            if (dominoes[i] == 'R')
                force = n;
            else if (dominoes[i] == 'L')
                force = 0;
            else
                force = std::max(force - 1, 0);

            forces[i] += force;
        }

        // right to left --> left
        force = 0;
        for (int i{n - 1}; i >= 0; i--)
        {
            if (dominoes[i] == 'L')
                force = n;
            else if (dominoes[i] == 'R')
                force = 0;
            else
                force = std::max(force - 1, 0);
            forces[i] -= force;
        }

        std::string answer{};
        for (int force : forces)
            answer += (force > 0 ? 'R' : force < 0 ? 'L' : '.');

        return answer;
    }
};
