func maximumSum(nums []int) int {
    m := make(map[int]int)
    res := -1
    for _, num := range nums {
        sum := 0
        temp := num
        for num > 0 {
            sum += num % 10
            num /= 10
        }
        if v, ok := m[sum]; ok {
            res = max(res, v + temp)
            m[sum] = max(v, temp)
        } else {
            m[sum] = temp
        }
    }
    return res
}
