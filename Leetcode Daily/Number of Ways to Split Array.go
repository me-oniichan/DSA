func waysToSplitArray(nums []int) int {
    suffix := make([]int64, len(nums))
    suffix[len(nums)-1] = int64(0)
    for i := len(nums)-2; i >= 0; i-- {
        suffix[i] = suffix[i+1] + int64(nums[i+1])
    }
    suffix[len(nums)-1] = math.MaxInt64
    res := 0
    prefix := int64(0)
    for i, num := range nums {
        prefix += int64(num)
        if prefix >= suffix[i] {
            res++
        }
    }
    return res
}
