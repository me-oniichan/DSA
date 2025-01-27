func checkIfPrerequisite(numCourses int, prerequisites [][]int, queries [][]int) []bool {
    graph := make([][]int, numCourses)
    for _, p := range prerequisites {
        graph[p[0]] = append(graph[p[0]], p[1])
    }
    
    dp := make([][]bool, numCourses)
    for i := 0; i < numCourses; i++ {
        dp[i] = make([]bool, numCourses)
    }
    
    for i := 0; i < numCourses; i++ {
        visited := make([]bool, numCourses)
        dfs(i, i, graph, dp, visited)
    }
    
    res := make([]bool, len(queries))
    for i, q := range queries {
        res[i] = dp[q[0]][q[1]]
    }
    return res
}

func dfs(start, cur int, graph [][]int, dp [][]bool, visited []bool) {
    if visited[cur] {
        return
    }
    visited[cur] = true
    for _, next := range graph[cur] {
        dp[start][next] = true
        dfs(start, next, graph, dp, visited)
    }
}
