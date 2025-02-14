func removeOccurrences(s, part string) string {
	for {
		if strings.Contains(s, part) {
			s = strings.Replace(s, part, "", 1)
		} else {
			break
		}
	}
	return s
}
