func xorAllNums(nums1 []int, nums2 []int) int {
    if len(nums1)%2 == 0 && len(nums2)%2 == 0 {
        return 0
    }
    var res int

    if len(nums1)%2 == 1 {
        for _, num := range nums2{
            res ^= num
        }
    }

    if len(nums2)%2 == 1 {
        for _, num := range nums1{
            res ^= num
        }
    }

    return res
}
