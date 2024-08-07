var lessThan20 = []string{"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"}
var tens = []string{"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"}

func numberToWords(num int) string {
	if num == 0 {
		return "Zero"
	}
	res := ""
	for i, unit := range []string{"", "Thousand", "Million", "Billion"} {
		if num%1000 != 0 {
			res = helper(num%1000) + unit + " " + res
		}
		num /= 1000
	}
	return strings.TrimSpace(res)
}

func helper(num int) string {
	if num == 0 {
		return ""
	} else if num < 20 {
		return lessThan20[num] + " "
	} else if num < 100 {
		return tens[num/10] + " " + helper(num%10)
	} else {
		return lessThan20[num/100] + " Hundred " + helper(num%100)
	}
}
