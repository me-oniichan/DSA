type TreeNode struct {
    Val int
    Left *TreeNode
    Right *TreeNode
}

func minimumOperations(root *TreeNode) int {
    currlevel := []*TreeNode{root}
    totalswaps := 0
    
    for len(currlevel) > 0 {
        nextlevel := []*TreeNode{}
        hmap := map[int]int{}
        sortedvalues := []int{}
        for i, node := range currlevel {
            hmap[node.Val] = i
            sortedvalues = append(sortedvalues, node.Val)
            if node.Left != nil {
                nextlevel = append(nextlevel, node.Left)
            }
            if node.Right != nil {
                nextlevel = append(nextlevel, node.Right)
            }
        }
        sort.Ints(sortedvalues)
        for i, val := range sortedvalues {
            targetindex := hmap[val]
            if i != targetindex {
                totalswaps += 1
                hmap[val], hmap[currlevel[i].Val] = i, targetindex
                currlevel[i], currlevel[targetindex] = currlevel[targetindex], currlevel[i]
            }
        }
        
        currlevel = nextlevel
    }

    return totalswaps

}
