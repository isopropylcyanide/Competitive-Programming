package main

import "fmt"

func numIslands(grid [][]byte) int {
	if grid == nil || len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	islands := 0
	for i := 0; i < len(grid); i++ {
		for j := 0; j < len(grid[0]); j++ {
			if grid[i][j] == 1 {
				islands += floodFill(i, j, grid)
			}
		}
	}
	return islands
}

func floodFill(i int, j int, grid [][]byte) int {
	if isOutOfBounds(i, j, grid) || grid[i][j] != 1 {
		return 0
	}
	grid[i][j] = 0
	floodFill(i+1, j, grid)
	floodFill(i-1, j, grid)
	floodFill(i, j+1, grid)
	floodFill(i, j-1, grid)
	return 1
}

func isOutOfBounds(i int, j int, grid [][]byte) bool {
	return i < 0 || i >= len(grid) || j < 0 || j >= len(grid[0])
}

func main() {
	grid := [][]byte{
		{1, 1, 1, 1, 0},
		{1, 1, 0, 1, 0},
		{1, 1, 0, 0, 0},
		{0, 0, 0, 0, 0},
	}
	fmt.Println(numIslands(grid))
}
