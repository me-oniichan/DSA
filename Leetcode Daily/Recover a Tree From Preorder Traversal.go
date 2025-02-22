/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func recoverFromPreorder(traversal string) *TreeNode {
    var stack []*TreeNode
    for i := 0; i < len(traversal); {
        level := 0
        for traversal[i] == '-' {
            level++
            i++
        }
        val := 0
        for i < len(traversal) && traversal[i] != '-' {
            val = val * 10 + int(traversal[i] - '0')
            i++
        }
        node := &TreeNode{Val: val}
        if level == len(stack) {
            if len(stack) > 0 {
                stack[len(stack) - 1].Left = node
            }
        } else {
            stack = stack[:level]
            stack[len(stack) - 1].Right = node
        }
        stack = append(stack, node)
    }
    return stack[0]
}
