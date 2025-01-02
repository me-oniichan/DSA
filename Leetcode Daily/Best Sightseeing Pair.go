func maxScoreSightseeingPair(values []int) int {
    maxScore := 0
    maxI := values[0]
    for j := 1; j < len(values); j++ {
        maxScore = max(maxScore, maxI + values[j] - j)
        maxI = max(maxI, values[j] + j)
    }
    return maxScore
}
