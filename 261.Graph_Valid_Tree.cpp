#include <vector>

/*
 * Goal: Check whether is it a valid tree or not
 *
 * Intuition:
 * A valid tree is a graph without cycle. So we just need to find whether there is a cycle.
 * The easiest algorithm to find whether a graph contain a cycle or not is thru Union Find algo
 * Time Complexity: O(m*n)
 * */
class Solution
{
  private:
    // Time Complexity: O(m)
    int findParent(int i, std::vector<int> &parents)
    {
        if (parents[i] != i)
            parents[i] = findParent(parents[parents[i]], parents);

        return parents[i];
    }

  public:
    bool validTree(int n, std::vector<std::vector<int>> &edges)
    {
        std::vector<int> parents(n);
        // Initially each node is own parent
        for (int i{}; i < n; i++)
            parents[i] = i;

        for (const auto &edge : edges)
        {
            if (findParent(edge[0], parents) == findParent(edge[1], parents))
                return false;

            // Since different parent then join them together
            parents[findParent(edge[0], parents)] = findParent(edge[1], parents);

            n--;
        }

        return n == 1;
    }
};
