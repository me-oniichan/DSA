func wordSubsets(words1 []string, words2 []string) []string {
    hmap := make([]int, 26)    
    for _, word := range words2 {
        temp := make([]int, 26)
        for _, c := range word {
            temp[c - 'a']++
        }
        for i := 0; i < 26; i++ {
            hmap[i] = max(hmap[i], temp[i])
        }
    }

    res := []string{}
    for _, word := range words1 {
        temp := make([]int, 26)
        for _, c := range word {
            temp[c - 'a']++
        }
        if isSubset(temp, hmap) {
            res = append(res, word)
        }
    }
    return res
}

func isSubset(temp, hmap []int) bool {
    for i := 0; i < 26; i++ {
        if temp[i] < hmap[i] {
            return false
        }
    }
    return true
}
