func lowerBound(items [][]int,  target int) int {
    l, r := 0, len(items)
    for l < r {
        m := (l + r)/2
        if items[m][0] <= target {
            l = m + 1
        } else {
            r = m
        }
    }
    
    if l == len(items) || items[l][0] > target{
        if l == 0{
            return 0
        }
        return items[l-1][1]
    }
    return items[l][1]
}
func maximumBeauty(items [][]int, queries []int) []int {
    sort.Slice(items, func(i, j int) bool {
        if items[i][0] == items[j][0] {
            return items[i][1] < items[j][1]
        }
        return items[i][0] < items[j][0]
    })
    
    for i := 1; i < len(items); i++ {
        items[i][1] = max(items[i][1], items[i-1][1])
    }

    fmt.Println(items)

    for q := range queries {
        queries[q] = lowerBound(items, queries[q])
    }

    return queries
}
