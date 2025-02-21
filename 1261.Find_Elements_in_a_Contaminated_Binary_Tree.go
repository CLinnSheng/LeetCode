/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
type FindElements struct {
	vals map[int]bool
}

func Constructor(root *TreeNode) FindElements {
	FE := FindElements{vals: make(map[int]bool)}
	dfs(root, 0, &FE)
	return FE
}

func dfs(node *TreeNode, currentVal int, FE *FindElements) {
	if node == nil {
		return
	}

	FE.vals[currentVal] = true
	dfs(node.Left, currentVal*2+1, FE)
	dfs(node.Right, currentVal*2+2, FE)
}

func (this *FindElements) Find(target int) bool {
	return this.vals[target]
}

/**
 * Your FindElements object will be instantiated and called as such:
 * obj := Constructor(root);
 * param_1 := obj.Find(target);
 */
