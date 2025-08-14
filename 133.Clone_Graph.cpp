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
 * Goal: Return a deep copy of the graph
 *
 * Intuition:
 * We need to clone every single node in the graph and also the relationship between nodes should be the same
 * We can dfs through the graph to find out all the nodes. We can use a hashmap to map the old node to the new node
 * We also can use the map to determine whether is the same node is being access or not, if is it then we simply just
 * return the newly created 1 instead of creating a new 1
 *
 * Time Complexity: O(n)
 * */

#include <unordered_map>
class Solution
{
  public:
    Node *cloneGraph(Node *node)
    {
        std::unordered_map<Node *, Node *> mapping;
        return dfs(mapping, node);
    }

    Node *dfs(std::unordered_map<Node *, Node *> &mapping, Node *currNode)
    {
        if (!currNode)
            return nullptr;

        // Check whether this node is visited or not
        if (mapping.find(currNode) != mapping.end())
            return mapping[currNode];

        Node *cloneNode = new Node(currNode->val);
        mapping[currNode] = cloneNode;

        for (const auto &neigh : currNode->neighbors)
            cloneNode->neighbors.emplace_back(dfs(mapping, neigh));

        return cloneNode;
    }
};
