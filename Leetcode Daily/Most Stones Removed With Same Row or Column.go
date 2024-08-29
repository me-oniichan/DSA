func removeStones(stones [][]int) int{
    n := len(stones)
    parent := make([]int, n)
    for i := 0; i < n; i++ {
        parent[i] = i
    }
    for i := 0; i < n; i++ {
        for j := i + 1; j < n; j++ {
            if stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1] {
                union(parent, i, j)
            }
        }
    }
    count := 0
    for i := 0; i < n; i++ {
        if parent[i] == i {
            count++
        }
    }
    return n - count
}

func union(parent []int, i, j int) {
    parent[find(parent, i)] = find(parent, j)
}

func find(parent []int, i int) int {
    if parent[i] != i {
        parent[i] = find(parent, parent[i])
    }
    return parent[i]
}
