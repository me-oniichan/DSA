func takeCharacters(s string, k int) int {
    hmap := [3]int{}
    right := -1
    for i := len(s)-1; i >= 0; i-- {
        hmap[s[i] - 'a']++
        if hmap[0] >= k && hmap[1] >= k && hmap[2] >= k {
            right = i
            break
        }
    }
    
    if right == -1 {
        return -1
    } else if k == 0{
        return 0
    }

    ans := len(s) - right
    for left := 0; left < len(s); left++ {
        hmap[s[left] - 'a']++

        for right < len(s) && (hmap[0] >= k && hmap[1] >= k && hmap[2] >= k) {
            ans = min(ans, len(s) - right + left+1)
            hmap[s[right] - 'a']--
            right++
        }

        if hmap[0] >= k && hmap[1] >= k && hmap[2] >= k{
            ans = min(ans, len(s) - right + left+1)
        }

    }

    return ans
}
