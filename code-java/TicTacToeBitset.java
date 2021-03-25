package com.random.aman;

import java.util.ArrayList;
import java.util.BitSet;
import java.util.List;

public class TicTacToeBitset {

    //maintain two flattened bitsets corresponding to the game;
    private final BitSet player1Game;
    private final BitSet player2Game;
    private final List<BitSet> winningPositions;
    private final int boardSize;

    public TicTacToeBitset(int n) {
        this.boardSize = n;
        this.player1Game = new BitSet(n);
        this.player2Game = new BitSet(n);
        this.winningPositions = getWinningPositions();
    }

    private List<BitSet> getWinningPositions() {
        //for horizontal victory,
        List<BitSet> winningPositions = new ArrayList<>();
        for (int i = 0; i + boardSize <= boardSize * boardSize; i += boardSize) {
            BitSet set = new BitSet();
            set.set(i, i + boardSize);
            winningPositions.add(set);
        }
        //for vertical victory
        for (int i = 0; i < boardSize; i++) {
            BitSet set = new BitSet();
            for (int j = i; j <= boardSize * boardSize - 1; j = j + boardSize) {
                set.set(j);
            }
            winningPositions.add(set);
        }
        //for diagonal victory: left
        BitSet leftDiagonal = new BitSet();
        BitSet rightDiagonal = new BitSet();
        for (int i = 0; i < boardSize; i++) {
            leftDiagonal.set(i * boardSize + i);
            rightDiagonal.set(i * boardSize + boardSize - 1 - i);
        }
        winningPositions.add(leftDiagonal);
        winningPositions.add(rightDiagonal);
        return winningPositions;
    }

    private boolean isWinningPosition(int player) {
        BitSet game = player == 1 ? player1Game : player2Game;
        for (BitSet winningPosition : winningPositions) {
            BitSet _game = (BitSet) game.clone();
            _game.and(winningPosition);
            if (_game.equals(winningPosition)) {
                System.out.println("Found a winning game " + _game + " for position " + winningPosition);
                return true;
            }
        }
        return false;
    }

    public int move(int row, int col, int player) {
        int flatPos = boardSize * row + col;
        BitSet game = player == 1 ? player1Game : player2Game;
        game.set(flatPos);
        if (game.cardinality() < boardSize) {
            //there's no way we can win
            return 0;
        }
//        printGame();
        return isWinningPosition(player) ? player : 0;
    }

    private void printGame() {
        System.out.println("*********************");
        System.out.println(player1Game);
        System.out.println(player2Game);
        System.out.println("*********************");
    }

    public static void main(String[] args) {
        TicTacToeBitset ticTacToe = new TicTacToeBitset(3);
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
