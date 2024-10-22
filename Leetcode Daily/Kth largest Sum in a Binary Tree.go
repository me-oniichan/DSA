/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func kthLargestLevelSum(root *TreeNode, k int) int64 {
    allsums := make([]]int64, 0)
    
    levelNodes := []*TreeNode{root}
    for len(levelNodes) > 0 {
        sum := int64(0)
        nextLevel := make([]*TreeNode, 0)
        for _, node := range levelNodes {
            sum += int64(node.Val)
            if node.Left != nil {
                nextLevel = append(nextLevel, node.Left)
            }
            if node.Right != nil {
                nextLevel = append(nextLevel, node.Right)
            }
        }
        allsums = append(allsums, sum)
        levelNodes = nextLevel
    }

    if k > len(allsums) {
        return -1
    }
    sort.Slice(allsums, func(i, j int) bool {
        return allsums[i] > allsums[j]
    })
    return allsums[k-1]
}
