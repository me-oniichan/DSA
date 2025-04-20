func numRabbits(answers []int) int {
    count := make(map[int]int)
    for _, answer := range answers {
        count[answer]++
    }

    total := 0
    for k, v := range count {
        total += (v + k) / (k + 1) * (k + 1)
    }

    return total
}
