#include <unordered_map>
#include <vector>

/*
 * Walk is allow in the graph wheere the same edge or vertex can be visit more than once
 * Cost of Walk: bitwise AND of the weights of the edges traversed
 *
 * Goal: Return an array where answer[i] denotes the minimum cost of a walk of query i
 *
 * Intuition:
 * At first thought, can we use dijkstra algorithm to solve this by tweaking the normal dijkstra algo work
 * We cant because of the weight is counted with bitwise AND. So the cost will actually capped at the maximum weight
 * from one of the edge, if we keep bitwise AND it will only get smaller and minimum is 0 Since walk is allow means that
 * the cost from any node to any node will be the same if they're in connected Since we mention about connected, then we
 * can use union find algorithm, to group all the connectd component. So for query where the source and destination does
 * not belong to the same component then is -1
 *
 * Time Complexity: linear time O(n)
 * */

class unionFind
{
  private:
    std::vector<int> parents;
    std::vector<int> sizes;

  public:
    unionFind(int n)
    {
        for (int i{}; i < n; i++)
            parents.emplace_back(i);

        sizes = std::vector<int>(n, 1);
    }

    // O(n)
    int findParent(const int &node)
    {
        if (node != parents[node])
            // path compression
            parents[node] = findParent(parents[parents[node]]);

        return parents[node];
    }

    // O(n)
    void join(const int &node1, const int &node2)
    {
        int parent1{findParent(node1)}, parent2{findParent(node2)};

        // in the same component
        if (parent1 == parent2)
            return;

        // join the smaller to the larger 1
        if (sizes[parent1] > sizes[parent2])
        {
            parents[parent2] = parent1;
            sizes[parent1] += sizes[parent2];
        }
        else
        {
            parents[parent1] = parent2;
            sizes[parent2] += sizes[parent1];
        }
    }
};

class Solution
{
  public:
    std::vector<int> minimumCost(int n, std::vector<std::vector<int>> &edges, std::vector<std::vector<int>> &query)
    {
        std::vector<int> answer;

        // connect the node first
        unionFind *uf = new unionFind(n);
        for (const auto &edge : edges)
            uf->join(edge[0], edge[1]);

        // now find the cost for each node, all node within the same component will having the same cost
        // O(E)
        std::unordered_map<int, int> node_cost;
        for (const auto &edge : edges)
        {
            // find out the root of the node / which component it belongs to
            int parent = uf->findParent(edge[0]);

            // if this is the first time we encounter this root then start with the current weight
            if (node_cost.count(parent) == 0)
                node_cost[parent] = edge[2];
            else
                // encounter before then just bitwise AND it, means that this node is belong to this component / having
                // hte same root
                node_cost[parent] &= edge[2];
        }

        // iterate through the query
        // O(q)
        for (const auto &q : query)
        {
            // find out their parent
            // check whether do they belong to the same component or not
            // if dont have the common root node, means is impossible for src to reach dest
            int parent1{uf->findParent(q[0])}, parent2{uf->findParent(q[1])};

            if (parent1 != parent2)
                answer.emplace_back(-1);
            else
                // either 1 is fine, because both of them have the same node
                answer.emplace_back(node_cost[parent1]);
        }
        return answer;
    }
};
