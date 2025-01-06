func minOperations(boxes string) []int {
    ans := make([]int, len(boxes))
    ans[len(boxes)-1] = 0
    balls := 0
    for i := len(boxes)-2; i >= 0; i-- {
        balls += int(boxes[i+1]-'0')
        ans[i] = ans[i+1] + balls
    }

    balls= 0
    moves := 0
    for i := 0; i < len(boxes); i++ {
        ans[i] += moves
        balls += int(boxes[i]-'0')
        moves += balls
    }
    return ans
}
