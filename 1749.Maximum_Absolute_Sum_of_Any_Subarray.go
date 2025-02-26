
func maxAbsoluteSum(nums []int) int {
	var maxNegativeSum, maxPositiveSum int
	var currPositiveSum, currNegativeSum int

	// use kadane algorithm
	// so basically we will just iterate the array twice but we can do it at once
	for _, num := range nums {
		currPositiveSum = max(currPositiveSum+num, num)
		maxPositiveSum = max(currPositiveSum, maxPositiveSum)

		currNegativeSum = min(currNegativeSum+num, num)
		maxNegativeSum = min(currNegativeSum, maxNegativeSum)
	}

	return max(maxPositiveSum, abs(&maxNegativeSum))
}

func abs(num *int) int {
	if *num < 0 {
		return -1 * *num
	}
	return *num
}
