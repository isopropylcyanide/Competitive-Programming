package main

import "fmt"

/**
You want to schedule a list of jobs in d days. Jobs are dependent (i.e To work on the i-th job, you have to finish all the jobs j where 0 <= j < i).
You have to finish at least one task every day. The difficulty of a job schedule is the sum of difficulties of each day of the d days. The difficulty of a day is the maximum difficulty of a job done in that day.

Given an array of integers jobDifficulty and an integer d. The difficulty of the i-th job is jobDifficulty[i].
Return the minimum difficulty of a job schedule. If you cannot find a schedule for the jobs return -1.
*/

func nextGreaterElements(nums []int) []int {
	n := len(nums)
	nextLarger := make([]int, n)
	for i, _ := range nextLarger {
		nextLarger[i] = -1
	}
	stack := make([]int, 0, 2*n)

	for i := 0; i < n*2; i++ {
		for len(stack) > 0 && nums[stack[len(stack)-1]] < nums[i%n] {
			nextLarger[stack[len(stack)-1]] = nums[i%n]
			stack = stack[:len(stack)-1]
		}
		stack = append(stack, i%n)
	}
	return nextLarger
}

func main() {
	//v := []int{7, 1, 7, 1, 7, 1}
	v := []int{1, 2, 1}
	fmt.Println(nextGreaterElements(v))
}
