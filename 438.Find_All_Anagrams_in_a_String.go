func findAnagrams(s string, p string) []int {
	var answer []int

	if len(p) > len(s) {
		return answer
	}

	freqS := make([]int, 26)
	freqP := make([]int, 26)

	for i := 0; i < len(p); i++ {
		freqP[int(p[i]-'a')]++
		freqS[int(s[i]-'a')]++
	}

	if fmt.Sprint(freqP) == fmt.Sprint(freqS) {
		answer = append(answer, 0)
	}

	left, right := 0, len(p)

	for right < len(s) {
		freqS[int(s[left]-'a')]--
		freqS[int(s[right]-'a')]++

		if fmt.Sprint(freqP) == fmt.Sprint(freqS) {
			answer = append(answer, left+1)
		}

		left++
		right++
	}
	return answer
}
