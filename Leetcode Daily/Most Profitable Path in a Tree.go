func mostProfitablePath(edges [][]int, bob int, amount []int) int {
    n := len(amount)
    tree := make([][]int, len(amount))
    for _, edge := range edges {
        tree[edge[0]] = append(tree[edge[0]], edge[1])
        tree[edge[1]] = append(tree[edge[1]], edge[0])
    }
    
    depth := make([]int, len(amount))
    for i := 0; i < len(amount); i++ {
        depth[i] = n+1
    }
    var dfs func(node, parent, bobdep int) bool 
    dfs = func(node, parent, bobdep int) bool{
        if node == 0{
            depth[0] = bobdep
            return true
        }
        for _, child := range tree[node] {
            if child == parent {
                continue
            }
            if dfs(child, node, bobdep+1){
                depth[node] = bobdep
                return true
            }
        }
        return false
    }

    dfs(bob, -1, 0)

    queue := make([][4]int, 0)
    queue = append(queue, [4]int{0, 0, 0, -1})
    maxProfit := math.MinInt
    for len(queue) > 0 {
        node, dep, prevProfit, parent := queue[0][0], queue[0][1], queue[0][2], queue[0][3]
        queue = queue[1:]
        var profit int
        if dep == depth[node] {
            profit = prevProfit + amount[node]/2
        } else if dep < depth[node] {
            profit = prevProfit + amount[node]
        } else {
            profit = prevProfit
        }
        
        if len(tree[node]) == 1 && node != 0{
            // if profit > prevProfit{
            maxProfit = max(maxProfit, profit)
            // } 
            // else{
            //     maxProfit = max(maxProfit, prevProfit)
            // }
        }

        for _, child := range tree[node] {
            if child == parent {
                continue
            }
            queue = append(queue, [4]int{child, dep+1, profit, node})
        }
    }
    return maxProfit
}
