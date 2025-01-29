func findRedundantConnection(edges [][]int) []int {
    graph := make([]map[int]bool, len(edges)+1)
    for i := range graph {
        graph[i] = make(map[int]bool, 0)
    }
    for _, edge := range edges {
        graph[edge[0]][edge[1]] = true
        graph[edge[1]][edge[0]] = true
    }
    queue := make([]int, 0)
    for i := 1; i < len(graph); i++ {
        if len(graph[i]) == 1 {
            queue = append(queue, i)
        }
    }
    for len(queue) > 0 {
        node := queue[0]
        queue = queue[1:]
        for k := range graph[node] {
            delete(graph[k], node)
            delete(graph[node], k)
            if len(graph[k]) == 1 {
                queue = append(queue, k)
            }
        }
    }
    for i := len(edges)-1; i >= 0; i-- {
        if _, ok := graph[edges[i][0]][edges[i][1]]; ok {
            return edges[i]
        }
    }
    return nil
}
