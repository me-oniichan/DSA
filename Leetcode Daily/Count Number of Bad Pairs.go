func countBadPairs(nums []int) int64 {
    var goodPairs int64 = 0
    group := make(map[int]int64)
    for i, num := range nums {
        key := num - i
        goodPairs += group[key]
        group[key]++
    }
    toatalPairs := int64(len(nums))*(int64(len(nums))-1)/2
    return toatalPairs -goodPairs
}
