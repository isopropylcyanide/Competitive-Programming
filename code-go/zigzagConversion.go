package main

import (
	"fmt"
	"strings"
)

/*
Write the code that will take a string and make this conversion given a number of rows:
https://leetcode.com/problems/zigzag-conversion/
*/

/*
Idea is to map each index of the string to a "level" which ranges from 0 to numRows -1
Once we have this map, we can iterate over each index in order and map[level] -> [string]
Then we simply print the level one by one. Since spacing is not required
Space complexity: O(N) map Time Complexity O(N) dominated by traversal
*/

/**
Smarter way to find level using mod
        .                   .
      .   .              .     .
   .          .       .            .
 .                .                   .
*/
func convert(s string, numRows int) string {
	if numRows <= 1 {
		return s
	}
	levelRunes := make([][]rune, numRows, numRows)
	n := numRows - 1
	for i, v := range s {
		var level int
		if i%n == 0 {
			if (i/n)%2 == 1 {
				level = n // else level = 0
			}
		} else {
			// either on increasing path or decreasing path
			if (i/n)%2 == 0 {
				// increasing path
				level = i % n
			} else {
				level = (-i % n) + n
				// decreasing path
			}
		}
		levelRunes[level] = append(levelRunes[level], v)
		fmt.Printf("Appending %c to level: %d\n", v, level)
	}
	var sb strings.Builder
	for _, runes := range levelRunes {
		for _, r := range runes {
			sb.WriteRune(r)
		}
	}
	return sb.String()
}

/**
To map each index, we simply traverse it. Value of level is given by a triangular functio
However, since I'm dumb, I create this function myself
*/
func convertDumb(s string, numRows int) string {
	if numRows <= 1 {
		return s
	}
	levelRunes := make([][]rune, numRows, numRows)
	count, sign := -1, 1
	for _, v := range s {
		if sign == 1 {
			count += 1
		} else {
			count -= 1
		}
		levelRunes[count] = append(levelRunes[count], v)
		fmt.Printf("Appending %c to level: %d\n", v, count)
		if count+1 == numRows {
			sign = -1
		} else if count == 0 {
			sign = 1
		}
	}
	var sb strings.Builder
	for _, runes := range levelRunes {
		for _, r := range runes {
			sb.WriteRune(r)
		}
	}
	return sb.String()
}

func main() {
	fmt.Println(convert("PAYPALISHIRING", 4))
	// fmt.Println(convert("PAYPALISHIRING", 3))
	// fmt.Println(convert("PAYPALISHIRING", 2))
	// fmt.Println(convert("PAYPALISHIRING", 1))
}
