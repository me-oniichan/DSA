func maxUniqueSplit(s string) int {
    return dfs(s, make(map[string]bool))
}

func dfs(s string, visited map[string]bool) int {
    if len(s) == 0 {
        return 0
    }
    res := 0
    for i := 1; i <= len(s); i++ {
        if visited[s[:i]] {
            continue
        }
        visited[s[:i]] = true
        res = max(res, 1 + dfs(s[i:], visited))
        visited[s[:i]] = false
    }
    return res
}

func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}
