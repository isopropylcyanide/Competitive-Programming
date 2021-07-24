package main

import "fmt"

/** Given a string s, return true if a permutation of the string could form a palindrome. **/

func canPermutePalindrome(s string) bool {
	// if length is even, each character must occur even
	// if length is odd, each character must occur even except one
	n := len(s)
	charCounts := make(map[rune]int)
	for _, ch := range s{
		charCounts[ch] += 1
	}
	allEven, oddCounters := true, 0
	for _, v := range charCounts{
		if v % 2 != 0 {
			allEven = false
			oddCounters += 1
		}
	}
	if n % 2 == 0 {
		return allEven && oddCounters == 0
	} else{
		return oddCounters == 1
	}
}

func main() {
	fmt.Println(canPermutePalindrome("code"))
	fmt.Println(canPermutePalindrome("aab"))
	fmt.Println(canPermutePalindrome("carerac"))
}