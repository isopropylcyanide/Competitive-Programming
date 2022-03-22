package tictactoe

import (
	"fmt"
	"math/big"
	"strings"
)

type Game struct {
	boardSize    int
	winningHands []*bitset
	playerXHand  *bitset
	playerOHand  *bitset
}

type GameResultType int

const (
	Incomplete GameResultType = iota
	PlayerXWinner
	PlayerOWinner
	NoResult
	Invalid
)

func NewGame(boardSize int) *Game {
	return &Game{
		boardSize:    boardSize,
		winningHands: getWinningHands(boardSize),
		playerXHand:  newBitset(),
		playerOHand:  newBitset(),
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

func (g *Game) Move(player string, x, y int) bool {
	if player != "X" && player != "O" {
		return false
	}
	index := x*g.boardSize + y
	if player == "X" {
		g.playerXHand.SetBit(index)
	} else {
		g.playerOHand.SetBit(index)
	}
	return true
}

func (g *Game) Solve() GameResultType {
	fmt.Println(g.playerXHand)
	fmt.Println(g.playerOHand)

	// for a game to have a winner, either player must have at least n tries
	// the difference between the two players cannot be > 1
	if g.playerXHand.ones < g.boardSize || g.playerOHand.ones < g.boardSize {
		return Incomplete
	}
	if abs(g.playerXHand.ones, g.playerOHand.ones) > 1 {
		return Incomplete
	}
	return g.solveBitSet()
}

// FromFlatInput parses input of the form
//	"X", "", "X",
//	"", "X", "",
//	"O", "O", "O",
func (g *Game) FromInput(input []string) bool {
	for ind, val := range input {
		if val == "X" {
			g.playerXHand.SetBit(ind)
		} else if val == "O" {
			g.playerOHand.SetBit(ind)
		} else if val != "" {
			return false
		}
	}
	return true
}

// FromFlatInput parses input of the form "XEOEXEEOX"
func (g *Game) FromFlatInput(input string) bool {
	inp := make([]string, 9)

	for ind, s := range input {
		if s == 'X' {
			inp[ind] = "X"
		} else if s == 'O' {
			inp[ind] = "O"
		} else {
			inp[ind] = ""
		}
	}
	return g.FromInput(inp)
}

func (g *Game) solveBitSet() GameResultType {
	// for each player check if they win, and both cannot win
	var winnerX, winnerO bool
	for _, hand := range g.winningHands {
		if hand.Matches(g.playerXHand) {
			winnerX = true
		} else if hand.Matches(g.playerOHand) {
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
