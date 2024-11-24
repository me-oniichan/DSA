func maxMatrixSum(matrix [][]int) int64 {
    negCount := 0
    minAbs := 1000000
    sum := 0
    for _, row := range matrix {
        for _, val := range row {
            if val < 0 {
                negCount++
                val = -val
            }
            if val < minAbs {
                minAbs = val
            }
            sum += val
        }
    }
    if negCount % 2 == 0 {
        return int64(sum)
    }
    return int64(sum - 2 * minAbs)
}
