func maxDifference(s string) int {
	freq := make([]int, 26)
	for _, c := range s {
		freq[c-'a']++
	}

	minEven, maxOdd := 100001, 0
	for _, count := range freq {
		if count == 0 {
			continue
		}
		if count%2 == 0 {
			if count < minEven {
				minEven = count
			}
		} else {
			if count > maxOdd {
				maxOdd = count
			}
		}
	}

	return maxOdd - minEven
}
