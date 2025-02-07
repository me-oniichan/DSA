func tupleSameProduct(nums []int) int {
    m := make(map[int]int)
    n := len(nums)
    res := 0
    for i:=0; i<n; i++ {
        for j:=i+1; j<n; j++ {
            m[nums[i]*nums[j]]++
        }
    }
    for _, v := range m {
        if v > 1 {
            res += v*(v-1)*4
        }
    }
    return res
}
