#include <unordered_set>
#include <vector>

/*
 * Goal: Find the number of components.
 * All nodes that connected together is considered as a component
 *
 * Intuition:
 * For this we can use unionFind algorithm to find all the nodes that connected together.
 * Then iterate through the array to find how many distinct parent are there
 *
 * Another method will just simply by use dfs on every single node, see how far it can go and mark those visited node
 * Time Complexity: O(n)
 * */
class Solution
{
  private:
    int findParent(const int &node, std::vector<int> &parents)
    {
        if (node != parents[node])
            parents[node] = findParent(parents[parents[node]], parents);

        return parents[node];
    }
    void unionFind(const int &node1, const int &node2, std::vector<int> &parents, std::vector<int> &ranks)
    {
        int parent1{findParent(node1, parents)};
        int parent2{findParent(node2, parents)};

        if (parent1 == parent2)
            return;

        if (ranks[parent1] > ranks[parent2])
        {
            parents[parent2] = parent1;
            ranks[parent1] += ranks[parent2];
        }
        else
        {
            parents[parent1] = parent2;
            ranks[parent2] += ranks[parent1];
        }
    }

  public:
    int countComponents(int n, std::vector<std::vector<int>> &edges)
    {
        std::vector<int> parents(n), ranks(n, 1);
        for (int i{}; i < n; i++)
            parents[i] = i;

        for (const auto &edge : edges)
            unionFind(edge[0], edge[1], parents, ranks);

        // Build the parents again after connecting all the comonent
        for (int i{}; i < n; i++)
            findParent(i, parents);

        std::unordered_set<int> answer(parents.begin(), parents.end());
        return answer.size();
    }
};
