func delNodes(root *TreeNode, to_delete []int) [] * TreeNode{
    set := make(map[int]bool)
    for _, v := range to_delete {
        set[v] = true
    }
    res := make([] * TreeNode, 0)
    dfs(root, nil, set, &res)
    if !set[root.Val] {
        res = append(res, root)
    }
    return res
}

func dfs(node, parent *TreeNode, set map[int]bool, res *[] * TreeNode) *TreeNode {
    if node == nil {
        return nil
    }
    node.Left = dfs(node.Left, node, set, res)
    node.Right = dfs(node.Right, node, set, res)
    if set[node.Val] {
        if node.Left != nil {
            *res = append(*res, node.Left)
        }
        if node.Right != nil {
            *res = append(*res, node.Right)
        }
        return nil
    }
    return node
}
