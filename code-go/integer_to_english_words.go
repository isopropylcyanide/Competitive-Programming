package main

import (
	"fmt"
	"strconv"
)

// Convert a non-negative integer num to its English words representation.

var (
	space               string         = " "
	posSignificantValue map[int]string = map[int]string{
		9: "Billion",
		6: "Million",
		3: "Thousand",
		2: "Hundred",
		1: "Tens",
		0: "Ones",
	}
	integerStringValue map[int]string = map[int]string{
		0: "Zero",
		1: "One",
		2: "Two",
		3: "Three",
		4: "Four",
		5: "Five",
		6: "Six",
		7: "Seven",
		8: "Eight",
		9: "Nine",
	}
	integerTensValue map[int]string = map[int]string{
		10: "Ten",
		11: "Eleven",
		12: "Twelve",
		13: "Thirteen",
		14: "Fourteen",
		15: "Fifteen",
		16: "Sixteen",
		17: "Seventeen",
		18: "Eighteen",
		19: "Nineteen",
	}
	integerTensSpecialValue map[int]string = map[int]string{
		2: "Twenty",
		3: "Thirty",
		4: "Forty",
		5: "Fifty",
		6: "Sixty",
		7: "Seventy",
		8: "Eighty",
		9: "Ninety",
	}
)

func isStringAValidRemainder(remainder string) bool {
	if len(remainder) == 0 {
		return false
	}
	var hasNonZeroCharacter bool
	for _, v := range remainder {
		if v != '0' {
			hasNonZeroCharacter = true
			break
		}
	}
	return hasNonZeroCharacter
}

func numberToWords(num int) string {
	if num < 10 {
		return integerStringValue[num]
	}
	if num < 20 {
		return integerTensValue[num]
	}
	s := strconv.Itoa(num)
	i, n, msbMark, seenSignificant := 0, len(s), 0, false
	var numUntilSignificantMsb string

	for i < n {
		msbMark = n - 1 - i
		//whenever you see a significant msb stop
		if significantValue, ok := posSignificantValue[msbMark]; !seenSignificant && ok != false {
			numUntilSignificantMsb += string(s[i])
			//we found it add the current digit to val
			seenSignificant = true
			var left string
			if msbMark == 1 {
				left = integerTensSpecialValue[int(s[i]-'0')]
			} else {
				intVal, _ := strconv.Atoi(numUntilSignificantMsb)
				left = numberToWords(intVal) + space + significantValue
			}
			remainder := s[i+1:]
			//if remainder is all zeroes or empty, we don't bother
			if isStringAValidRemainder(remainder) {
				intVal, _ := strconv.Atoi(remainder)
				right := numberToWords(intVal)
				return left + space + right

			} else {
				return left
			}

		} else {
			//we haven't seen it..keep building the number
			numUntilSignificantMsb += string(s[i])
		}
		msbMark -= 1
		i += 1
	}
	return ""
}

func main() {
	fmt.Println("0 :", numberToWords(0))
	fmt.Println("7 :", numberToWords(7))
	fmt.Println("10 :", numberToWords(10))
	fmt.Println("12 :", numberToWords(12))
	fmt.Println("47 :", numberToWords(47))
	fmt.Println("100 :", numberToWords(100))
	fmt.Println("553 :", numberToWords(553))
	fmt.Println("647 :", numberToWords(647))
	fmt.Println("1300 :", numberToWords(1300))
	fmt.Println("3647 :", numberToWords(3647))
	fmt.Println("10000 :", numberToWords(10000))
	fmt.Println("10009 :", numberToWords(10009))
	fmt.Println("83647 :", numberToWords(83647))
	fmt.Println("483647 :", numberToWords(483647))
	fmt.Println("7483647 :", numberToWords(7483647))
	fmt.Println("47483647 :", numberToWords(47483647))
	fmt.Println("12300009 :", numberToWords(12300009))
	fmt.Println("147483647 :", numberToWords(147483647))
	fmt.Println("2147483647 :", numberToWords(2147483647))
}
