/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

/*
 * Return a deep copy of the graph
 * This is a graph problem, so dfs/bfs
 * DFS will be much more easier.
 * A few things need during DFS which is visited set, so we wont revisit the same node
 * We can just keep traversing from the parent node to its child node.
 * And keep every visited node in a set or whatever that track its, so that we no longer need to traverse down
 * Since we want the cloned nodes, we can map the original node to the clonned nodes
 * The base case of stop searching will just does we reach the end?
 *
 * Time Complexity: O(V + E)
 * Visiting every nodes and edges in the graph
 * Space Complexity: O(V)
 * Worst case the recursive stack will just go through all the node
 * */

#include <unordered_map>
class Solution
{
    std::unordered_map<Node *, Node *> map;

    Node *dfs(Node *node)
    {
        if (node == nullptr)
        {
            return nullptr;
        }

        // Check whether is it a visited node
        if (map.find(node) != map.end())
        {
            return map[node];
        }

        map[node] = new Node(node->val);

        // Visit all its neighbor
        for (auto neigh : node->neighbors)
        {
            map[node]->neighbors.push_back(dfs(neigh));
        }

        return map[node];
    }

  public:
    Node *cloneGraph(Node *node)
    {
        return dfs(node);
    }
};
