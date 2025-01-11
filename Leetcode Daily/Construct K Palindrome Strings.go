func canConstruct(s string, k int) bool {
	n := len(s)
	if n < k {
		return false
	}
	if n == k {
		return true
	}
	letterCounts := make([]int, 26)
	for _, char := range s {
		letterCounts[char-'a']++
	}
	oddCount := 0
	for _, count := range letterCounts {
		if count%2 != 0 {
			oddCount++
		}
	}
	if oddCount > k {
		return false
	}

	return true
}
