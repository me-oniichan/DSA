func maxCount(banned []int, n int, maxSum int) int {
    banMap := make(map[int]bool, len(banned))
    for _, b := range banned {
        banMap[b] = true
    }

    ans := 0
    sum := 0
    for i := 1; i <= n; i++ {
        if banMap[i] {
            continue
        }

        if sum+i > maxSum {
            break
        }

        sum += i
        ans++
    }

    return ans
}
