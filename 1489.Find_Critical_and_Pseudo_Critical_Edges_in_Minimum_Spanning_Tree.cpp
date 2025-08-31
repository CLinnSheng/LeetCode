#include <algorithm>
#include <numeric>
#include <vector>
using std::vector;

/*
 * Given a weighted undirected connected graph with n vertices.
 * edges[i] = [ai, bi, weighti] --> Bidirectional and weighted edge
 *
 * Goal: Find all the critical and pseudo-critical edges in the given graph's
 * minimum spanning tree(MST).
 * An MST edge whose deletion from the graph would cause the MST weight to increase is called critical edge
 * A pseudo-critical edge is that which can appear in some MSTs but not all.
 *
 * Intuition:
 * Find out the MST. then try out all possible MST by eliminating one of the edges to check whether does the weight is
 * less than the MST or not. If yes then is belong to critical. Take note that an edge cannot be in critical and
 * psuedo-critical While for pseudo-critical basically means is an important edge for forming the MST. We can make use
 * of unionFind data structure for us easily track whether got cycle or not
 * Time Complexity: O(E^3)
 * */

class UnionFind
{
    std::vector<int> parents, ranks;

  public:
    UnionFind(const int n) : parents(n), ranks(n, 1)
    {
        std::iota(parents.begin(), parents.end(), 0);
    }

    // O(lgn)
    int findParent(const int node)
    {
        if (node != parents[node])
            parents[node] = findParent(parents[parents[node]]);

        return parents[node];
    }

    bool unionSet(const int nodeA, const int nodeB)
    {
        int parentA{findParent(nodeA)}, parentB{findParent(nodeB)};

        if (parentA == parentB)
            return false;

        if (ranks[parentA] > ranks[parentB])
        {
            parents[parentB] = parentA;
            ranks[parentA] += ranks[parentB];
        }
        else
        {
            parents[parentA] = parentB;
            ranks[parentB] += ranks[parentA];
        }

        return true;
    }

    const std::vector<int> &getRanks() const
    {
        return this->ranks;
    }
};

class Solution
{
  public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
    {
        // O(E)
        for (int i{}; i < edges.size(); i++)
            // Preserve the original index
            edges[i].emplace_back(i);

        // O(Elg E)
        std::sort(edges.begin(), edges.end(), [](const auto &A, const auto &B) { return A[2] < B[2]; });

        UnionFind unionFind{n};
        int mstWeight{};

        // Connect the graph according to the weight
        // So basically at here we will get the MST
        // O(E*V)
        for (const auto &edge : edges)
            if (unionFind.unionSet(edge[0], edge[1]))
                mstWeight += edge[2];

        std::vector<int> critical, pseudo_critical;

        // O(E)
        for (const auto &edge : edges)
        {
            // Then try form a MST without current edge
            // For finding critical edge, check whether the MST formed is less than the least MST or not
            // O(V)
            UnionFind unionFindTempWithout{n};
            int tempMSTWeight{};

            // O(E)
            for (const auto &otherEdge : edges)
                if (edge[3] != otherEdge[3] && unionFindTempWithout.unionSet(otherEdge[0], otherEdge[1]))
                    tempMSTWeight += otherEdge[2];

            // Consider edge cases where couldnt form a MST
            if (tempMSTWeight > mstWeight ||
                *std::max_element(unionFindTempWithout.getRanks().begin(), unionFindTempWithout.getRanks().end()) != n)
            {
                critical.emplace_back(edge[3]);
                continue;
            }

            // Include current edge
            // Check whether is it an edge that included in MST or not
            UnionFind unionFindTempWith{n};
            // Include this edge
            unionFindTempWith.unionSet(edge[0], edge[1]);
            tempMSTWeight = edge[2];
            for (const auto &otherEdge : edges)
                if (otherEdge[3] != edge[3] && unionFindTempWith.unionSet(otherEdge[0], otherEdge[1]))
                    tempMSTWeight += otherEdge[2];

            if (tempMSTWeight == mstWeight)
                pseudo_critical.emplace_back(edge[3]);
        }

        return {critical, pseudo_critical};
    }
};
