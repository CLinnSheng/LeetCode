func checkWindow(freq [3]int) bool {
	return freq[0] > 0 && freq[1] > 0 && freq[2] > 0
}

func numberOfSubstrings(s string) int {
	var ans, left, right int
	freq := [3]int{}

	for right < len(s) {
		freq[s[right]-'a']++

		for checkWindow(freq) {
			ans += len(s) - right

			freq[s[left]-'a']--
			left++
		}
		right++
	}
	return ans
}
