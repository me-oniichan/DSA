func queryResults(limit int, queries [][]int) []int {
    colormap := make(map[int]int)
    result := make([]int, len(queries))
    curcolor := make(map[int]int) 

    for i, query := range queries {
        ball, color := query[0], query[1]

        if prevColor, ok := curcolor[ball]; ok {
            colormap[prevColor]--
            if colormap[prevColor] == 0 {
                delete(colormap, prevColor)
            }
        }

        curcolor[ball] = color
        colormap[color]++
        result[i] = len(colormap)
    }
    return result
}
