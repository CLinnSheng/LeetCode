package leetcode

func numOfSubarrays(arr []int) int {
	var oddCnt, sum, answer int
	evenCnt := 1

	for _, val := range arr {
		sum += val

		if sum%2 == 1 {
			answer += evenCnt
			oddCnt++
		} else {
			answer += oddCnt
			evenCnt++
		}
		answer %= int(1e9 + 7)
	}
	return answer
}
