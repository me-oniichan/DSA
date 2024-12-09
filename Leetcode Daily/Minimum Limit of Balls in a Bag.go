func minimumSize(nums []int, maxOperations int) int {
    l, r := 1, 1<<31-1
    for l < r {
        m := l + (r-l)/2
        if !canSplit(nums, m, maxOperations) {
            l = m + 1
        } else {
            r = m
        }
    }
    return l
}

func canSplit(nums []int, m, maxOperations int) bool {
    for _, num := range nums {
        maxOperations -= (num-1)/m
    }
    return maxOperations >= 0
}
