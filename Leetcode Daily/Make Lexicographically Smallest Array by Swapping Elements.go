func lexicographicallySmallestArray(nums []int, limit int) []int {
    copyarr := make([]int, len(nums))
    copy(copyarr, nums)
    sort.Ints(copyarr)
    groupnum := 0
    numbertogroup := make(map[int]int)
    grouptoindex := make(map[int]int)
    grouptoindex[0] = 0
    numbertogroup[copyarr[0]] = 0
    for i := 1; i < len(nums); i++ {
        if abs(copyarr[i] - copyarr[i-1]) > limit {
            groupnum++
            grouptoindex[groupnum] = i
        }
        numbertogroup[copyarr[i]] = groupnum
    }

    for i := 0; i < len(nums); i++ {
        group := numbertogroup[nums[i]]
        minindex := grouptoindex[group]
        numAtMinIndex := copyarr[minindex]
        nums[i] = numAtMinIndex
        grouptoindex[group]++
    }
    return nums
}

func abs(a int) int {
    if a < 0 {
        return -a
    }
    return a
}
