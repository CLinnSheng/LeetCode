#include <vector>

/*
 * You are given a connected undirected graph with n nodes labeled from 1 to n. Initially, it contained no cycles and
 * consisted of n-1 edges.
 * Goal: Return an edge that can be remove to make the graph dont have cycle.
 *
 * Intuition:
 * So the qeustion is telling us the edge is added 1 by 1 and no cycle initially. Then eventually there will beo ne edge
 * that will form a cycle within the graph. So we need to find out that edge. We can use unionFind algorithm to connect
 * the nodes. Such that when we find out the 2 nodes share the same parent means that it will form a cycl
 * */
class Solution
{
  private:
    int findParent(const int &node, std::vector<int> &parents)
    {
        if (parents[node] != node)
            parents[node] = findParent(parents[parents[node]], parents);
        return parents[node];
    }
    bool unionFind(const int &node1, const int &node2, std::vector<int> &parents)
    {
        int parent1{findParent(node1, parents)}, parent2{findParent(node2, parents)};

        if (parent1 == parent2)
            return true;

        // If doesnt form the cycle or in another way share the same parent
        // then we connected these 2 noeds together
        parents[parent1] = parent2;
        return false;
    }

  public:
    std::vector<int> findRedundantConnection(std::vector<std::vector<int>> &edges)
    {
        std::vector<int> parents;
        // Initially all nodes are its own parent
        for (int i{}; i <= edges.size(); i++)
            parents.emplace_back(i);

        for (const auto &edge : edges)
            if (unionFind(edge[0], edge[1], parents))
                return {edge[0], edge[1]};
        return {};
    }
};
