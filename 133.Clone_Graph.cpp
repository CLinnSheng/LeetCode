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
Goal: Return a deep copy of the graph
Intuition: Everytime need to produce a deep copy we need to keep track of the
old and the new 1 at the same time So hash data structure can be use to keep
track of the new and old 1 together, so we know where to place our new 1 based
on our old one use dfs and if visited we return back Time Complexity: O(n) Space
Complexity: O(n)
*/
class Solution {
public:
  Node *cloneGraph(Node *node) {
    std::unordered_map<Node *, Node *> mapping_Old_New;
    return dfs(mapping_Old_New, node);
  }

  Node *dfs(std::unordered_map<Node *, Node *> &mapping_Old_New, Node *node) {
    if (node == nullptr)
      return nullptr;

    // check we visit this node before or not
    if (mapping_Old_New.count(node))
      return mapping_Old_New[node];

    Node *copy = new Node(node->val);
    mapping_Old_New[node] = copy;

    for (const auto &nb : node->neighbors)
      copy->neighbors.emplace_back(dfs(mapping_Old_New, nb));

    return copy;
  }
};
