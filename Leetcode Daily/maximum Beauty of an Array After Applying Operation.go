func maximumBeauty(nums []int, k int) int {
    sort.Ints(nums)
    maxLen := 1
    for l,r := 0,0; r < len(nums); r++{
        for nums[r] - nums[l] > 2*k{
            l++
        }
        maxLen = max(maxLen, r-l+1)
    }
    return maxLen
}
