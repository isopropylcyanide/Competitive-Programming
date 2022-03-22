package tictactoe

import (
	"fmt"
	"math/big"
	"strings"
)

type GameSolver struct {
	boardSize    int
	winningHands []*bitset
}

type GameResultType int

const (
	Incomplete GameResultType = iota
	PlayerXWinner
	PlayerOWinner
	NoResult
	Invalid
)

func NewGameSolver(boardSize int) *GameSolver {
	return &GameSolver{
		boardSize:    boardSize,
		winningHands: getWinningHands(boardSize),
	}
}

type bitset struct {
	b    *big.Int
	ones int
}

func newBitset() *bitset {
	var b big.Int
	return &bitset{
		b:    &b,
		ones: 0,
	}
}

func (bs *bitset) String() string {
	var sb strings.Builder
	for _, x := range bs.b.Bits() {
		sb.WriteString(fmt.Sprintf("%064b", x))
	}
	sb.WriteString(fmt.Sprintf(" with -> %d set", bs.ones))
	return sb.String()
}

func (bs *bitset) SetBit(ind int) {
	bs.b.SetBit(bs.b, ind, 1)
	bs.ones += 1
}

func (bs *bitset) Matches(other *bitset) bool {
	if other.ones < bs.ones {
		return false
	}
	// if every bit set in this bitset matches the one in other bitset, this is a match
	and := &big.Int{}
	and = and.And(other.b, bs.b)
	return bs.b.Cmp(and) == 0
}

func (s *GameSolver) Solve(input []string) GameResultType {
	// create bitset for each player
	posX := newBitset()
	posO := newBitset()
	for ind, val := range input {
		if val == "X" {
			posX.SetBit(ind)
		} else if val == "O" {
			posO.SetBit(ind)
		} else if val != "" {
			return Invalid
		}
	}
	fmt.Println(posX)
	fmt.Println(posO)

	// for a game to have a winner, either player must have at least n tries
	// the difference between the two players cannot be > 1
	if posX.ones < s.boardSize || posO.ones < s.boardSize {
		return Incomplete
	}
	if abs(posX.ones, posO.ones) > 1 {
		return Incomplete
	}
	return s.solveBitSet(posX, posO)
}

func (s *GameSolver) solveBitSet(posX, posO *bitset) GameResultType {
	// for each player check if they win, and both cannot win
	var winnerX, winnerO bool
	for _, hand := range s.winningHands {
		if hand.Matches(posX) {
			winnerX = true
		} else if hand.Matches(posO) {
			winnerO = true
		}
	}
	if winnerX && winnerO {
		return Invalid
	}
	if winnerX {
		return PlayerXWinner
	} else if winnerO {
		return PlayerOWinner
	}
	return NoResult
}

func getWinningHands(n int) []*bitset {
	// get all horizontals
	winning := make([]*bitset, 0, n*2+2)
	for i := 0; i < n*n-1; i += n {
		b := newBitset()
		for j := i; j < i+n; j++ {
			b.SetBit(j)
		}
		winning = append(winning, b)
	}
	// get all verticals
	for i := 0; i < n; i += 1 {
		b := newBitset()
		for j := i; j < n*n; j += n {
			b.SetBit(j)
		}
		winning = append(winning, b)
	}
	// mark both diagonals
	left := newBitset()
	right := newBitset()
	for i := 0; i < n; i++ {
		left.SetBit(i * (n + 1))
		right.SetBit(i*(n+1) + n - 1 - i)
	}
	winning = append(winning, left)
	winning = append(winning, right)
	return winning
}

func abs(a, b int) int {
	diff := a - b
	if diff < 0 {
		diff = diff * (-1)
	}
	return diff
}
