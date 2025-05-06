func countCompleteSubarrays(nums []int) int {
    n := len(nums)
    uniqueCount := 0
    countMap := make(map[int]int)
    for _, num := range nums {
        if countMap[num] == 0 {
            uniqueCount++
        }
        countMap[num]++
    }
    
    countMap = make(map[int]int)
    result := 0
    left := 0
    for right := 0; right < n; right++ {
        countMap[nums[right]]++
        if countMap[nums[right]] == 1 {
            uniqueCount--
        }
        
        for uniqueCount == 0 {
            result += n - right
            countMap[nums[left]]--
            if countMap[nums[left]] == 0 {
                uniqueCount++
            }
            left++
        }
    }

    return result
}
