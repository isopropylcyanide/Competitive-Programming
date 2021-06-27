package main

import (
	"fmt"
	"strings"
)

// Given an integer, convert it to a roman numeral.

var (
	numerals = []struct {
		val    int
		symbol string
	}{
		{val: 1000, symbol: "M"},
		{val: 900, symbol: "CM"},
		{val: 500, symbol: "D"},
		{val: 400, symbol: "CD"},
		{val: 100, symbol: "C"},
		{val: 90, symbol: "XC"},
		{val: 50, symbol: "L"},
		{val: 40, symbol: "XL"},
		{val: 10, symbol: "X"},
		{val: 9, symbol: "IX"},
		{val: 5, symbol: "V"},
		{val: 4, symbol: "IV"},
		{val: 1, symbol: "I"},
	}
)

func intToRoman(num int) string {
	var sb strings.Builder
	for i := 0; i < len(numerals); i++ {
		//repeatedly divide num by the value of this literal until
		numeralVal := numerals[i].val
		for num >= numeralVal {
			num -= numeralVal
			sb.WriteString(numerals[i].symbol)
		}
	}
	return sb.String()
}

func main() {
	fmt.Println("3999: ", intToRoman(3999))
	fmt.Println("1994: ", intToRoman(1994))
	fmt.Println("3: ", intToRoman(3))
	fmt.Println("99: ", intToRoman(99))
}
