func eventualSafeNodes(graph [][]int) []int {
    n := len(graph)
    is_safe := make([]bool, n)
    visited := make([]bool, n)
    res := make([]int, 0)
    for i:=0; i < n; i++{
        if !visited[i]{
            visited[i] = true
            check_safe(i, graph, is_safe, visited)
        }
        if is_safe[i]{
            res = append(res, i)
        }
    }
    return res
}

func check_safe(i int, graph [][]int, is_safe []bool, visited []bool) bool{
    if len(graph[i]) == 0{
        is_safe[i] = true
        return true
    }
    safe := true
    for _, node := range graph[i]{
        if visited[node]{
            safe = safe && is_safe[node]
        }else{
            visited[node] = true
            
            safe = check_safe(node, graph, is_safe, visited) && safe
        }
    }
    is_safe[i] = safe
    return safe
}
