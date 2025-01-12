func smallestSubarrays(nums []int) []int {
    htable := make([]int, 31)
    res := make([]int, len(nums))
    for i := 0; i < 31; i++ {
        htable[i] = -1
    }
    
    for i:=len(nums)-1; i>=0; i-- {
        for j:=0; j<31; j++ {
            if getBit(nums[i], j) == 1 {
                htable[j] = i
            }
        }

        maxIndex := slices.Max(htable)
        res[i] = max(maxIndex - i + 1,1)
    }

    return res
}

func getBit(num int, i int) int {
    return (num >> i) & 1
}
