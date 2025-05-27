func max(a, b int) int {
    if a > b {
        return a
    }
    return b
}

func largestPathValue(colors string, edges [][]int) int {
    n := len(colors)
    if n == 0 {
        return 0
    }

    graph := make([][]int, n)
    inDegree := make([]int, n)
    for _, edge := range edges {
        graph[edge[0]] = append(graph[edge[0]], edge[1])
        inDegree[edge[1]]++
    }

    colorCount := make([][]int, n)
    for i := 0; i < n; i++ {
        colorCount[i] = make([]int, 26)
    }

    queue := []int{}
    processed := 0

    for i := 0; i < n; i++ {
        if inDegree[i] == 0 {
            queue = append(queue, i)
            colorCount[i][colors[i]-'a'] = 1
            processed++
        }
    }

    maxColorValue := 0
    
    head := 0
    for head < len(queue) {
        node := queue[head]
        head++

        currentPathValueAtNode := 0
        for k := 0; k < 26; k++ {
            currentPathValueAtNode = max(currentPathValueAtNode, colorCount[node][k])
        }
        maxColorValue = max(maxColorValue, currentPathValueAtNode)

        for _, neighbor := range graph[node] {
            for k_idx := 0; k_idx < 26; k_idx++ {
                valToPropagate := colorCount[node][k_idx]
                if k_idx == int(colors[neighbor]-'a') {
                    valToPropagate++
                }
                colorCount[neighbor][k_idx] = max(colorCount[neighbor][k_idx], valToPropagate)
            }

            inDegree[neighbor]--
            if inDegree[neighbor] == 0 {
                queue = append(queue, neighbor)
                processed++
            }
        }
    }

    if processed != n {
        return -1
    }

    return maxColorValue
}
