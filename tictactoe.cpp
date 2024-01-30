#include <iostream>
#include <vector>
using namespace std;
void displayBoard(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            cout << cell << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool checkWin(const vector<vector<char>> &board, char player) {
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}
bool checkDraw(const vector<vector<char>> &board) {
    for (const auto &row : board) {
        for (char cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}
int main() {
    vector<vector<char>> board(3, vector<char>(3, ' '));  // Initialize 3x3 game board
    char currentPlayer = 'X';
    cout << "Welcome to Tic-Tac-Toe!" << endl;
    do {
        displayBoard(board);
        cout << "Player " << currentPlayer << ", enter your move (row and column, e.g., 1 2): ";
        int row, col;
        cin >> row >> col;
        if (board[row - 1][col - 1] == ' ') {
            board[row - 1][col - 1] = currentPlayer;
            if (checkWin(board, currentPlayer)) {
                displayBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                break;
            }
            if (checkDraw(board)) {
                displayBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        } else {
            cout << "Cell already occupied. Try again." << endl;
        }
    } while (true);
    char playAgain;
    cout << "Do you want to play again? (y/n): ";
    cin >> playAgain;
    if (playAgain == 'y' || playAgain == 'Y') {
        main();  // Restart the game
    } else {
        cout << "Thanks for playing!" << endl;
    }
    return 0;
}
