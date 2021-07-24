package main

import "fmt"

/** Given two strings s and t, return true if t is an anagram of s, and false otherwise. **/

func isAnagram(s string, t string) bool {
	// two strings are anagrams if they can be rearranged using the same number of letters
	if len(s) != len(t){
		return false
	}
	charCountsA := make(map[rune]int)
	for i:= 0; i < len(s); i++{
		charCountsA[rune(s[i])] += 1
		charCountsA[rune(t[i])] -= 1
	}
	for _, v := range charCountsA{
		if v != 0{
			return false
		}
	}
	return true
}

func main() {
	fmt.Println(isAnagram("anagram", "nagaram"))
	fmt.Println(isAnagram("rat", "car"))
}