func canBeEqual(target []int, arr []int) bool{
    hmap := make(map[int]int)
    for _, v := range target {
        hmap[v]++
    }
    for _, v := range arr {
        hmap[v]--
    }
    for _, v := range hmap {
        if v != 0 {
            return false
        }
    }
    return true
}
