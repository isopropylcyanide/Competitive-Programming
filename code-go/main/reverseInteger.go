package main

import (
	"fmt"
	"math"
)

func reverseUtil(num, revNum int) int {
	if num == 0 {
		return revNum
	} else {
		lastDigit := num % 10
		revNum := revNum*10 + lastDigit
		if revNum > math.MaxInt32 {
			return 0
		}
		return reverseUtil(num/10, revNum)
	}
}

func abs(x int) (int, int) {
	if x < 0 {
		return -1, -x
	} else {
		return 1, x
	}
}
func reverse(x int) int {
	sgn, val := abs(x)
	ans := reverseUtil(val, 0)
	return ans * sgn
}

func main() {
	fmt.Println(reverse(-123))
	fmt.Println(reverse(1534236469))
	fmt.Println(int64(reverse(1534236469)))

}
