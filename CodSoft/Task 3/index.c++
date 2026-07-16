#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    cout << "\nTic-Tac-Toe Board: \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows, columns, and diagonals for a win
    for (int i = 0; i < 3; i++) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||  // Check row
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) { // Check column
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

// Function to check if the board is full (draw)
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') { // If there is an empty space, it's not a draw yet
                return false;
            }
        }
    }
    return true; // All spaces are filled, it's a draw
}

// Function to check if a cell is empty
bool isCellEmpty(const vector<vector<char>>& board, int row, int col) {
    return board[row][col] == ' ';
}

int main() {
    char playAgain = 'y'; // Variable to track if the players want to play another game

    while (playAgain == 'y' || playAgain == 'Y') {
        // Initialize the Tic-Tac-Toe board with empty spaces
        vector<vector<char>> board(3, vector<char>(3, ' '));

        int row, col;
        char currentPlayer = 'X';  // Start with player X
        bool gameWon = false;

        while (true) {
            printBoard(board);  // Print the board before each turn

            // Prompt the current player for their move
            cout << "Player " << currentPlayer << ", enter your move (row and column: 0, 1, or 2): ";
            cin >> row >> col;

            // Validate the move
            if (row < 0 || row >= 3 || col < 0 || col >= 3 || !isCellEmpty(board, row, col)) {
                cout << "Invalid move, try again!" << endl;
                continue;
            }

            // Update the board with the player's move
            board[row][col] = currentPlayer;

            // Check if the current player has won
            if (checkWin(board, currentPlayer)) {
                printBoard(board);
                cout << "Player " << currentPlayer << " wins!" << endl;
                gameWon = true;
                break;
            }

            // Check for a draw
            if (checkDraw(board)) {
                printBoard(board);
                cout << "It's a draw!" << endl;
                break;
            }

            // Switch players for the next turn
            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }

        // Ask if the players want to play again
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
    }

    cout << "Thank you for playing!" << endl;
    return 0;
}
