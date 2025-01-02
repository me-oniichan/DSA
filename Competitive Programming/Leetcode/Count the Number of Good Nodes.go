func countGoodNodes(edges [][]int)int{
    n := len(edges)+1
    tmap := make([][]int, n)
    for i:=0; i < n; i++{
        tmap[i] = make([]int,0)
    }
    visited := make([]bool, n)

    for _, elem := range edges{
        tmap[elem[0]] = append(tmap[elem[0]],elem[1])
        tmap[elem[1]] = append(tmap[elem[1]],elem[0])
    }

    visited[0] = true
    ans := 0
    dfs(0, tmap, visited, &ans)

    return ans
}

func dfs(idx int, tmap [][]int, visited []bool, ans *int) int{
    childCount := 0
    subchildmap := make(map[int]bool,0)

    for _, child := range tmap[idx]{
        if !visited[child]{
            visited[child] = true
            subChild := dfs(child, tmap, visited, ans)
            subchildmap[subChild] = true
            childCount += subChild
        }
    }

    if len(subchildmap) <= 1{
        *ans+=1
    }

    return childCount+1
}
