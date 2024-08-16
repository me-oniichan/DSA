func maxDistance(arrays [][]int) int {
    min1, min2 := 10001, 10001
    max1, max2 := -10001, -10001
    ma1, mi1 := 0, 0
    for i := 0; i < len(arrays); i++ {
        if arrays[i][0] < min1 {
            min2 = min1
            min1 = arrays[i][0]
            mi1 = i
        } else if arrays[i][0] < min2 {
            min2 = arrays[i][0]
        }
        if arrays[i][len(arrays[i])-1] > max1 {
            max2 = max1
            max1 = arrays[i][len(arrays[i])-1]
            ma1 = i
        } else if arrays[i][len(arrays[i])-1] > max2 {
            max2 = arrays[i][len(arrays[i])-1]
        }
    }
    if mi1 != ma1 {
        return max1 - min1
    }
    return max(max1 - min2, max2 - min1)
}
