package main

import (
	"fmt"
)

// Given an roman numeral, convert it to integer

type romanNumeral struct {
	symbol       string
	val          int
	dependencies map[byte]romanNumeral
}

var (
	_numerals = map[byte]romanNumeral{
		'M': {symbol: "M", val: 1000},
		'D': {symbol: "D", val: 500},
		'C': {symbol: "C", val: 100, dependencies: map[byte]romanNumeral{
			'M': {symbol: "M", val: 900},
			'D': {symbol: "D", val: 400},
		}},
		'L': {symbol: "L", val: 50},
		'X': {symbol: "X", val: 10, dependencies: map[byte]romanNumeral{
			'C': {symbol: "C", val: 90},
			'L': {symbol: "L", val: 40},
		}},
		'V': {symbol: "V", val: 5},
		'I': {symbol: "I", val: 1, dependencies: map[byte]romanNumeral{
			'X': {symbol: "X", val: 9},
			'V': {symbol: "V", val: 4},
		}},
	}
)

func romanToInt(s string) int {
	// process string character by character
	// if a particular character has a 2nd dependencies and length doesn't exceed, check it
	// add the sum represented by the character
	var number int
	i, n := 0, len(s)
	for i < n {
		// guaranteed that only valid characters exist
		numeral := _numerals[s[i]]
		if numeral.dependencies == nil {
			number += numeral.val
		} else {
			// we need to check if the next char is in bounds and in dependency
			foundDep := false
			if i+1 < n {
				if dep, ok := numeral.dependencies[s[i+1]]; ok {
					i += 1
					number += dep.val
					foundDep = true
				}
			}
			if !foundDep {
				number += numeral.val
			}
		}
		i += 1
	}
	return number
}

func main() {
	//fmt.Println("MCMXCIV: ", romanToInt("MCMXCIV"))
	fmt.Println("III: ", romanToInt("III"))
}
