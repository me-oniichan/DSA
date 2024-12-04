func addSpaces(s string, spaces []int) string {
    var res bytes.Buffer
    spIdx := 0
    for i, c := range s {
        for ;spIdx < len(spaces) && i == spaces[spIdx]; spIdx++ {
            res.WriteByte(' ')
        }
        res.WriteByte(byte(c))
    }
    return res.String()
}
