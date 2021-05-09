package main

import (
	"fmt"
	"math"
)

/**
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the i-th job, you have to finish all the jobs j where 0 <= j < i).
You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done in that day.

Given an array of integers jobDifficulty and an integer d. The difficulty of the i-th job is jobDifficulty[i].
Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.
*/
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func sum(difficulty []int) int {
	var cumulativeSum int
	for _, v := range difficulty {
		cumulativeSum += v
	}
	return cumulativeSum
}

func maxInSlice(difficulty []int) int {
	maxSoFar := math.MinInt64
	for _, v := range difficulty {
		maxSoFar = max(maxSoFar, v)
	}
	return maxSoFar
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func f(index int, days int, A []int, dp [][]int) int {
	if dp[days][index] != -1 {
		return dp[days][index]
	}
	if days == 0 {
		return maxInSlice(A[index:])
	}
	includeValue, bisectMinValue := 0, math.MaxInt64
	for i := index; i < len(A)-days; i++ {
		includeValue = max(includeValue, A[i])
		bisectMinValue = min(bisectMinValue, includeValue+f(i+1, days-1, A, dp))
	}
	dp[days][index] = bisectMinValue
	return bisectMinValue
}

func minDifficulty(difficulty []int, d int) int {
	if d > len(difficulty) {
		return -1
	}
	if d == len(difficulty) {
		return sum(difficulty)
	}
	if d == 1 {
		return maxInSlice(difficulty)
	}
	dp := buildDPArray(difficulty, d)
	return f(0, d-1, difficulty, dp)
}

func buildDPArray(difficulty []int, d int) [][]int {
	dp := make([][]int, d)
	for i := 0; i < d; i++ {
		dp[i] = make([]int, len(difficulty))
		for j := 0; j < len(dp[i]); j++ {
			dp[i][j] = -1
		}
	}
	return dp
}

func main() {
	//v := []int{7, 1, 7, 1, 7, 1}
	v := []int{11, 111, 22, 222, 33, 333, 44, 444}
	days := 6
	fmt.Printf("\nDifficulty %v at %d days: %d\n", v, days, minDifficulty(v, days))
}
