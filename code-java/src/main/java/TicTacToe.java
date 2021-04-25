public class TicTacToe {

    private final char[][] game;
    private final int boardSize;

    /**
     * Initialize your data structure here.
     */
    public TicTacToe(int n) {
        this.boardSize = n;
        this.game = new char[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                game[i][j] = '-';
            }
        }
    }

    private boolean isWinningPosition(int player) {
        char toCheck = getPlayerChar(player);
        //check all rows
        for (int i = 0; i < boardSize; i++) {
            int matchCount = 0;
            for (int j = 0; j < boardSize; j++) {
                matchCount = game[i][j] == toCheck ? matchCount + 1 : matchCount;
            }
            if (matchCount == boardSize) {
                return true;
            }
        }
        //check all cols
        for (int j = 0; j < boardSize; j++) {
            int matchCount = 0;
            for (int i = 0; i < boardSize; i++) {
                matchCount = game[i][j] == toCheck ? matchCount + 1 : matchCount;
            }
            if (matchCount == boardSize) {
                return true;
            }
        }
        //check diagonals left
        int matchCountLeft = 0;
        int matchCountRight = 0;
        for (int i = 0; i < boardSize; i++) {
            matchCountLeft = game[i][i] == toCheck ? matchCountLeft + 1 : matchCountLeft;
            matchCountRight = game[i][boardSize - 1 - i] == toCheck ? matchCountRight + 1 : matchCountRight;
        }
        if (matchCountLeft == boardSize || matchCountRight == boardSize) {
            return true;
        }
        return false;
    }

    private char getPlayerChar(int player) {
        return player == 1 ? 'X' : 'O';
    }

    /**
     * Player {player} makes a move at ({row}, {col}).
     *
     * @param row    The row of the board.
     * @param col    The column of the board.
     * @param player The player, can be either 1 or 2.
     * @return The current winning condition, can be either:
     * 0: No one wins.
     * 1: Player 1 wins.
     * 2: Player 2 wins.
     */
    public int move(int row, int col, int player) {
        game[row][col] = getPlayerChar(player);
        printGame();
        return isWinningPosition(player) ? player : 0;
    }

    private void printGame() {
        for (int i = 0; i < boardSize; i++) {
            for (int j = 0; j < boardSize; j++) {
                System.out.print(game[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
        System.out.println();
    }

    public static void main(String[] args) {
        TicTacToe ticTacToe = new TicTacToe(2);

        System.out.println(ticTacToe.move(0, 1, 1)); // return 0 (no one wins)
        System.out.println(ticTacToe.move(1, 1, 2)); // return 0 (no one wins)
        System.out.println(ticTacToe.move(1, 0, 1)); // return 0 (no one wins)

    }
}
/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
