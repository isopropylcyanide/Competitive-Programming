package main

import (
	"fmt"
	"math"
)

type XYPoint struct {
	max_x_left  int
	min_x_right int
	max_y_left  int
	min_y_right int
}

func cond(predicate bool, truthy, falsy int) int {
	if predicate {
		return truthy
	}
	return falsy
}

func getInterestingElements(a, b []int, a_part_idx, b_part_idx int) *XYPoint {
	max_x_left, min_x_right := math.MinInt32, math.MaxInt32
	max_y_left, min_y_right := math.MinInt32, math.MaxInt32
	if a_part_idx > 0 {
		max_x_left = a[a_part_idx-1]
	}
	if a_part_idx < len(a) {
		min_x_right = a[a_part_idx]
	}
	if b_part_idx > 0 {
		max_y_left = b[b_part_idx-1]
	}
	if b_part_idx < len(b) {
		min_y_right = b[b_part_idx]
	}
	return &XYPoint{max_x_left, min_x_right, max_y_left, min_y_right}
}

func findMedianSortedArrays(a []int, b []int) float64 {
	n := len(a) + len(b)
	splitSize := (n + 1) / 2
	//assume size(a) >= size(b)
	if len(a) > len(b) {
		a, b = b, a
	}
	//optimally partition the array
	low, high := 0, len(a)
	for low <= high {
		a_part_idx := low + (high-low)/2
		b_part_idx := splitSize - a_part_idx

		fmt.Printf("\nSplitting a at %d as %v and %v\n", a_part_idx, a[:a_part_idx], a[a_part_idx:])
		fmt.Printf("Splitting b at %d as %v and %v\n", b_part_idx, b[:b_part_idx], b[b_part_idx:])
		p := getInterestingElements(a, b, a_part_idx, b_part_idx)

		if p.max_x_left <= p.min_y_right && p.max_y_left <= p.min_x_right {
			fmt.Printf("Found median at index %d \n", a_part_idx)
			larger_left := math.Max(float64(p.max_x_left), float64(p.max_y_left))

			if n%2 == 0 {
				//even..middle of two larger
				larger_right := math.Min(float64(p.min_x_right), float64(p.min_y_right))
				return float64(larger_left+larger_right) / 2.0

			} else {
				return larger_left
			}
		} else if p.max_x_left > p.min_y_right {
			//too far right, go left
			high = a_part_idx - 1

		} else {
			//too far left, go right
			low = a_part_idx + 1
		}
	}
	return 0.0
}

func main() {
	a := []int{4, 20, 32, 50, 55, 61}
	b := []int{1, 15, 22, 30, 70}
	fmt.Println("Median: ", findMedianSortedArrays(a, b))
}
