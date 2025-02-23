
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func constructFromPrePost(preorder []int, postorder []int) *TreeNode {
	// base cases
	if len(preorder) == 0 {
		return nil
	}

	// The first element in the preorder traversal is the root
	root := &TreeNode{Val: preorder[0]}

	if len(preorder) == 1 {
		return root
	}

	// finding the index of the left subtree's root in the postorder traversal
	leftRootVal := preorder[1]
	var leftRootIndex int

	for i, val := range postorder {
		if val == leftRootVal {
			leftRootIndex = i
			break
		}
	}

	root.Left = constructFromPrePost(preorder[1:leftRootIndex+2], postorder[:leftRootIndex+1])
	root.Right = constructFromPrePost(preorder[leftRootIndex+2:], postorder[leftRootIndex+1:len(postorder)-1])

	return root
}
