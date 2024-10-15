func minimumSteps(s string) int64 {
    balls := []rune(s)
    ans := 0

    for left, right := 0,0; right < len(balls);{
        if balls[right] == '1'{
            ans += int64(right - left)
            left++
            right++
        }else{
            right++
        }
    }

    return int64(ans)
}
