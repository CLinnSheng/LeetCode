/**
 * Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode *left;
 *    TreeNode *right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 *
 * Goal: Return true if the target value exists in the recovered binary tree.
 * Intuition: DFS to recover the tree and insert into a set, so that we can know
 * it in O(1)
 * Time Complexity: O(n)
 */

#include <unordered_set>
class FindElements
{
  private:
    std::unordered_set<int> values;
    void dfs(const int &parentVal, TreeNode *node)
    {
        if (node == nullptr)
            return;

        values.insert(parentVal);

        dfs(parentVal * 2 + 1, node->left);
        dfs(parentVal * 2 + 2, node->right);
    }

  public:
    FindElements(TreeNode *root)
    {
        dfs(0, root);
    }

    bool find(int target)
    {
        return values.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
