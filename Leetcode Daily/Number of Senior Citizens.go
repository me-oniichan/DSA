func countSeniors(details []string) int {
    count := 0
    for _, detail := range details {
        if detail[11:13] >= "60" {
            count++
        }
    }
}
