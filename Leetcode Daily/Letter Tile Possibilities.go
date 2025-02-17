func numTilePossibilities(tiles string) int {
    m := make(map[rune]int)
    for _, v := range tiles {
        m[v]++
    }
    var dfs func() int
    dfs = func() int {
        sum := 0
        for k, v := range m {
            if v == 0 {
                continue
            }
            sum++
            m[k]--
            sum += dfs()
            m[k]++
        }
        return sum
    }
    return dfs()
}
