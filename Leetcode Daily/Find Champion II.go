func findChampion(n int, edges [][]int) int {
    champs := make(map[int]bool)
    for i:=0; i < n; i++{
        champs[i] = true
    }
    for _, edge := range edges{
        delete(champs, edge[1])
    }

    if len(champs) != 1{
        return -1
    }

    for k := range champs{
        return k
    }
    return -1
}
