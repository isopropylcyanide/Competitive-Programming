package main

import (
	"fmt"
	"math"
)

type XYPoint struct {
	maxXLeft  int
	minXRight int
	maxYLeft  int
	minYRight int
}

func getInterestingElements(a, b []int, aPartIdx, bPartIdx int) *XYPoint {
	maxXLeft, minXRight := math.MinInt32, math.MaxInt32
	maxYLeft, minYRight := math.MinInt32, math.MaxInt32
	if aPartIdx > 0 {
		maxXLeft = a[aPartIdx-1]
	}
	if aPartIdx < len(a) {
		minXRight = a[aPartIdx]
	}
	if bPartIdx > 0 {
		maxYLeft = b[bPartIdx-1]
	}
	if bPartIdx < len(b) {
		minYRight = b[bPartIdx]
	}
	return &XYPoint{maxXLeft, minXRight, maxYLeft, minYRight}
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
		aPartIdx := low + (high-low)/2
		bPartIdx := splitSize - aPartIdx

		fmt.Printf("\nSplitting a at %d as %v and %v\n", aPartIdx, a[:aPartIdx], a[aPartIdx:])
		fmt.Printf("Splitting b at %d as %v and %v\n", bPartIdx, b[:bPartIdx], b[bPartIdx:])
		p := getInterestingElements(a, b, aPartIdx, bPartIdx)

		if p.maxXLeft <= p.minYRight && p.maxYLeft <= p.minXRight {
			fmt.Printf("Found median at index %d \n", aPartIdx)
			largerLeft := math.Max(float64(p.maxXLeft), float64(p.maxYLeft))

			if n%2 == 0 {
				//even..middle of two larger
				largerRight := math.Min(float64(p.minXRight), float64(p.minYRight))
				return (largerLeft + largerRight) / 2.0

			} else {
				return largerLeft
			}
		} else if p.maxXLeft > p.minYRight {
			//too far right, go left
			high = aPartIdx - 1

		} else {
			//too far left, go right
			low = aPartIdx + 1
		}
	}
	return 0.0
}

func main() {
	a := []int{4, 20, 32, 50, 55, 61}
	b := []int{1, 15, 22, 30, 70}
	fmt.Println("Median: ", findMedianSortedArrays(a, b))
}
