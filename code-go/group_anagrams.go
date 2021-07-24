package main

import (
	"bytes"
	"fmt"
)

/**
 Given an array of strings strs, group the anagrams together. You can return the answer in
 any order. An Anagram is a word or phrase formed by rearranging the letters of a different
 word or phrase, typically using all the original letters exactly once.
*/

func groupAnagrams(strs []string) [][]string {
	// the idea is to calculate an anagram hash for each string
	// you could sort each string to see what bucket it belongs to but that would be
	// inefficient, rather count the chars instead

	m := make(map[string][]string)
	for _, s := range strs{
		hash := calculateHash(s)
		m[hash] = append(m[hash], s)
	}

	var res [][]string
	for _, v := range m {
		res = append(res, v)
	}
	return res
}

func calculateHash(s string) string {
	var counter [26]int
	var hash bytes.Buffer

	for _, ch := range s{
		counter[int(ch) - 97] += 1
	}
	for i, v := range counter{
		if v != 0{
			hash.WriteString(fmt.Sprintf("%d->%d", i, v))
		}
	}
	return hash.String()
}

func main() {
	fmt.Println(groupAnagrams([]string{"eat","tea","tan","ate","nat","bat"}))
}