func findLengthOfShortestSubarray(arr []int) int {
    n := len(arr)
    left, right := 0, n-1
    for left < n-1 && arr[left] <= arr[left+1] {
        left++
    }
    if left == n-1 {
        return 0
    }
    for right > 0 && arr[right-1] <= arr[right] {
        right--
    }
    res := min(n-left-1, right)
    for i := 0; i <= left; i++ {
        if arr[i] <= arr[right] {
            res = min(res, right-i-1)
        } else if right < n-1 {
            right++
        } else {
            break
        }
    }
    return res
}
