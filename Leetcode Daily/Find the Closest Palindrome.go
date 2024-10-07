func nearestPalindromic(n string) string {
	lenN := len(n)
	i := 0
	if lenN%2 == 0 {
		i = lenN/2 - 1
	} else {
		i = lenN / 2
	}

	firstHalf, _ := strconv.ParseInt(n[:i+1], 10, 64)

	possibilities := []int64{
		halfToPalindrome(firstHalf, lenN%2 == 0),
		halfToPalindrome(firstHalf+1, lenN%2 == 0),
		halfToPalindrome(firstHalf-1, lenN%2 == 0),
		int64(math.Pow(10, float64(lenN-1))) - 1,
		int64(math.Pow(10, float64(lenN))) + 1,
	}

	nl, _ := strconv.ParseInt(n, 10, 64)
	diff := int64(math.MaxInt64)
	res := int64(0)

	for _, cand := range possibilities {
		if cand == nl {
			continue
		}
		if abs(cand-nl) < diff {
			diff = abs(cand - nl)
			res = cand
		} else if abs(cand-nl) == diff {
			if cand < res {
				res = cand
			}
		}
	}

	return strconv.FormatInt(res, 10)
}

func halfToPalindrome(left int64, even bool) int64 {
	res := left
	if !even {
		left /= 10
	}
	for left > 0 {
		res = res*10 + left%10
		left /= 10
	}
	return res
}

func abs(x int64) int64 {
	if x < 0 {
		return -x
	}
	return x
}

func main() {
	n := "123"
	fmt.Println(nearestPalindromic(n))
}
