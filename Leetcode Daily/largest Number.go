func largestNumber(nums []int) string{
    var strNums []string
    for _, num := range nums{
        strNums = append(strNums, strconv.Itoa(num))
    }
    sort.Slice(strNums, func(i, j int) bool{
        return strNums[i] + strNums[j] > strNums[j] + strNums[i]
    })
    if strNums[0] == "0"{
        return "0"
    }
    return strings.Join(strNums, "")
}
