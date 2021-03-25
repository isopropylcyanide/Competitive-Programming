package com.random.aman;

import java.util.BitSet;

public class TicTacToeBitsetNoSpace {

    //maintain two flattened bitsets corresponding to the game;
    private final BitSet player1Game;
    private final BitSet player2Game;
    private final int boardSize;

    public TicTacToeBitsetNoSpace(int n) {
        this.boardSize = n;
        this.player1Game = new BitSet(n);
        this.player2Game = new BitSet(n);
    }

    public int move(int row, int col, int player) {
        int flatPos = boardSize * row + col;
        BitSet game = player == 1 ? player1Game : player2Game;
        game.set(flatPos);
        if (game.cardinality() < boardSize) {
            return 0;
        }
        return checkGameAgainstWinningPositions(game) ? player : 0;
    }

    private boolean checkGameAgainstWinningPositions(BitSet game) {
        //for horizontal victory,
        for (int i = 0; i + boardSize <= boardSize * boardSize; i += boardSize) {
            BitSet set = new BitSet();
            set.set(i, i + boardSize);
            if (isGameWinning(game, set)) {
                return true;
            }
        }
        //for vertical victory
        for (int i = 0; i < boardSize; i++) {
            BitSet set = new BitSet();
            for (int j = i; j <= boardSize * boardSize - 1; j = j + boardSize) {
                set.set(j);
            }
            if (isGameWinning(game, set)) {
                return true;
            }
        }
        //for diagonal victory: left
        BitSet leftDiagonal = new BitSet();
        BitSet rightDiagonal = new BitSet();
        for (int i = 0; i < boardSize; i++) {
            leftDiagonal.set(i * boardSize + i);
            rightDiagonal.set(i * boardSize + boardSize - 1 - i);
        }
        if (isGameWinning(game, leftDiagonal)) {
            return true;
        }
        if (isGameWinning(game, rightDiagonal)) {
            return true;
        }
        return false;
    }

    private boolean isGameWinning(BitSet game, BitSet winningPosition) {
        BitSet _game = (BitSet) game.clone();
        _game.and(winningPosition);
        if (_game.equals(winningPosition)) {
            System.out.println("Found a winning game " + _game + " for position " + winningPosition);
            return true;
        }
        return false;
    }

    private void printGame() {
        System.out.println("*********************");
        System.out.println(player1Game);
        System.out.println(player2Game);
        System.out.println("*********************");
    }

    public static void main(String[] args) {
        TicTacToeBitsetNoSpace ticTacToe = new TicTacToeBitsetNoSpace(3);
        System.out.println(ticTacToe.move(0, 0, 1)); // return 0 (no one wins)
        System.out.println(ticTacToe.move(0, 2, 2)); // return 0 (no one wins)
        System.out.println(ticTacToe.move(2, 2, 1)); // return 0 (no one wins)
        System.out.println(ticTacToe.move(1, 1, 2)); // return 0 (no one wins)
        System.out.println(ticTacToe.move(2, 0, 1)); // return 0 (no one wins)
        System.out.println(ticTacToe.move(1, 0, 2)); // return 0 (no one wins)
        System.out.println(ticTacToe.move(2, 1, 1)); // return 1 (player 1 wins)

//        TicTacToeBitset ticTacToe = new TicTacToeBitset(2);
//        System.out.println(ticTacToe.move(0, 1, 1)); // return 0 (no one wins)
//        System.out.println(ticTacToe.move(1, 1, 2)); // return 0 (no one wins)
//        System.out.println(ticTacToe.move(1, 0, 1)); // return 0 (one wins)

    }
}
/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
