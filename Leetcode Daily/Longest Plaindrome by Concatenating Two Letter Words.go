func longestPalindrome(words []string) int {
	wordCount := make(map[string]int)
	for _, word := range words {
		wordCount[word]++
	}

	palindromeLength := 0
	hasOddCount := false

	for word, count := range wordCount {
		reverseWord := string(word[1]) + string(word[0])
		if word == reverseWord { 
			palindromeLength += (count / 2) * 4 
			if count%2 == 1 {
				hasOddCount = true 
			}
		} else if count > 0 && wordCount[reverseWord] > 0 {
			pairCount := min(count, wordCount[reverseWord])
			palindromeLength += pairCount * 4 
			wordCount[word] -= pairCount
			wordCount[reverseWord] -= pairCount
		}
	}

	if hasOddCount {
		palindromeLength += 2 
	}

	return palindromeLength
}
