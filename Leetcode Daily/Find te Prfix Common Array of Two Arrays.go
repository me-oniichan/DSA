func findThePrefixCommonArray(A []int, B []int) []int {
    var result []int
    count := 0
    var hist map[int]bool
    hist = make(map[int]bool, 0)
    for i:=0; i<len(A);i++{
        if A[i] == B[i]{
            count++
            result = append(result, count)
            continue
        }

        if hist[A[i]] == true{
            count++
        }
        if hist[B[i]] == true{
            count++
        }
        result = append(result, count)
        hist[A[i]] = true
        hist[B[i]] = true
    }
    return result
}
