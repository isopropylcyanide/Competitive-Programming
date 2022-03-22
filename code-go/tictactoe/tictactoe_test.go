package tictactoe

import (
	"testing"

	"github.com/stretchr/testify/assert"
)

func TestSolve(t *testing.T) {
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

	solver := NewGameSolver(3)
	for _, tc := range cases {
		result := solver.Solve(tc.game)
		assert.Equal(t, tc.want, result)
	}
}
