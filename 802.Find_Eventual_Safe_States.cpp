#include <functional>
#include <unordered_map>
#include <vector>

/*
 * Directed graph of n node label from [0, n - 1]. graph[i] is an integer array of nodes adjacent to node ith,
 * meaning there is an edge from node i to each node in graph[i].
 * Terminal Node: No outgoing edges.
 * Safe Node: Every possible path starting from that node leads to a terminal node.
 * Goal: Return an array containing all the safe nodes of the graph. (In ascending order)
 *
 * Intuition:
 * If we brute force it to dry run we will see some nodes we will traverse multiple time.
 * eg: graph = [[1,2],[2,3],[5],[0],[5],[],[]]
 * lets start from node 0. 0 -> 1 -> 2 -> 5, 0 -> 1 -> 3 -> 0 -> ... Cycle.
 *  from the first traversal we can deduce that node 5 & 2 is a safe node because all edges from this 2 node lead to
 * terminal node. and then we saw the 2nd path will lead to a cycle. We need to find a way to stop the cycle and thus 0
 * and 1 are no safe node. How can we do that? we can do it by using a hash map to hash every single node to a state
 * whether safe or not. So for example for the 4th node. 4 -> 5. we know 5 is a safe node and then there is only 1 edge
 * from 4 so we can deduce that 4 is safe. We dont need to go through all the path from 5 (if 5 have edges out from it)
 * because from the pervious traversal we already know that 5 is safe. So we can reduce the time complexity. Time
 * complexity: O(V + E) at worst go through every single node and edge Space Complexity: O(n)
 * */
class Solution
{
  public:
    std::vector<int> eventualSafeNodes(std::vector<std::vector<int>> &graph)
    {
        std::vector<int> answer;
        std::unordered_map<int, int> nodeState;

        std::function<bool(const int &index)> dfs = [&](const int &node) {
            // check whether we traverse before or not
            if (nodeState.count(node))
                return nodeState[node];

            // make it false by default first, so that we can check for cycle
            nodeState[node] = false;

            for (const auto &edge : graph[node])
                // if we found 1 edge from this node making an invalid path which doesnt reach the terminal node
                // we can straightaway deduce that this node is not a safe node, so no point on continuing process other
                // edges
                if (!dfs(edge))
                    return nodeState[node];

            // all edges lead to a terminal node
            // therefore this node is a safe node
            nodeState[node] = true;

            return nodeState[node];
        };

        for (int i{}; i < graph.size(); i++)
            if (dfs(i))
                answer.emplace_back(i);

        return answer;
    }
};
