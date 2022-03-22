package tictactoe

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestSolveWithParsedInput(t *testing.T) {
	cases := []struct {
		game []string
		want GameResultType
	}{
		{
			game: []string{
				"X", "", "X",
				"", "X", "",
				"O", "O", "O",
			},
			want: PlayerOWinner,
		},
		{
			game: []string{
				"X", "", "O",
				"", "X", "",
				"", "O", "X",
			},
			want: Incomplete,
		},
		{
			game: []string{
				"O", "X", "O",
				"O", "O", "X",
				"X", "O", "X",
			},
			want: NoResult,
		},
		{
			game: []string{
				"O", "X", "O",
				"", "", "",
				"", "", "",
			},
			want: Incomplete,
		},
		{
			game: []string{
				"O", "X", "O",
				"", "O", "",
				"", "", "",
			},
			want: Incomplete,
		},
		{
			game: []string{
				"O", "", "X",
				"O", "", "X",
				"O", "", "X",
			},
			want: Invalid,
		},
		{
			game: []string{
				"O", "", "X",
				"O", "", "C",
				"O", "", "",
			},
			want: Invalid,
		},
		{
			game: []string{
				"O", "X", "O",
				"", "X", "O",
				"", "", "",
			},
			want: Incomplete,
		},
		{
			game: []string{
				"O", "X", "O",
				"", "X", "O",
				"", "X", "",
			},
			want: PlayerXWinner,
		},
		{
			game: []string{
				"O", "O", "O",
				"X", "X", "X",
				"X", "O", "X",
			},
			want: Invalid,
		},
		{
			game: []string{
				"O", "O", "O",
				"X", "", "X",
				"X", "", "X",
			},
			want: PlayerOWinner,
		},
	}

	for _, tc := range cases {
		game := NewGame(3)
		if !game.FromInput(tc.game) {
			assert.Equal(t, tc.want, Invalid)
			return
		}
		result := game.Solve()
		assert.Equal(t, tc.want, result)
	}
}

func TestSolveWithMove(t *testing.T) {
	type moves struct {
		player string
		x, y   int
	}

	cases := []struct {
		moves []moves
		want  GameResultType
	}{
		{
			moves: []moves{
				{"X", 0, 0},
				{"O", 2, 0},
				{"X", 0, 0},
				{"X", 1, 1},
				{"O", 2, 1},
				{"X", 0, 2},
				{"O", 2, 2},
			},
			want: PlayerOWinner,
		},
		{
			moves: []moves{
				{"X", 0, 0},
				{"O", 2, 0},
				{"X", 0, 0},
			},
			want: Incomplete,
		},
		{
			moves: []moves{
				{"O", 0, 1},
				{"X", 2, 0},
				{"C", 0, 0},
			},
			want: Invalid,
		},
	}

	for _, tc := range cases {
		game := NewGame(3)
		for _, m := range tc.moves {
			if !game.Move(m.player, m.x, m.y) {
				assert.Equal(t, tc.want, Invalid)
				return
			}
		}
		result := game.Solve()
		assert.Equal(t, tc.want, result)
	}
}

func TestSolveWithFlatInput(t *testing.T) {
	cases := []struct {
		game string
		want GameResultType
	}{
		{
			game: "XEXEXOOOO",
			want: PlayerOWinner,
		},
		{
			game: "XEOEXEEOX",
			want: Incomplete,
		},
		{
			game: "OXOOOXXOX",
			want: NoResult,
		},
		{
			game: "XXOXXOOOX",
			want: PlayerXWinner,
		},
	}

	for _, tc := range cases {
		game := NewGame(3)
		if !game.FromFlatInput(tc.game) {
			assert.Equal(t, tc.want, Invalid)
			return
		}
		result := game.Solve()
		assert.Equal(t, tc.want, result)
	}
}
