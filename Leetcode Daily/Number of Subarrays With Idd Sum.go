func numOfSubarrays(arr []int) int {
    odd, even, sum := 0, 1, 0
    res := 0
    for _, v := range arr {
        sum += v
        if sum % 2 == 0 {
            res += odd
            res%=1000000007
            even++
        } else {
            res += even
            res%=1000000007
            odd++
        }
    }
    return res % 1000000007
}
