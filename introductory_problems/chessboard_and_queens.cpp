/*
Your task is to place eight queens on a chessboard so that no two queens are attacking each other. As an additional challenge, each square is either free or reserved, and you can only place queens on the free squares. However, the reserved squares do not prevent queens from attacking each other.

How many possible ways are there to place the queens?
*/

#include <iostream>
#include <vector>
using namespace std;
#define ll long long

bool isSafe(vector<string> &board, int row, int col) {
    for (int i = 0; i < 8; i++) {
        if (board[row][i] == 'Q' || board[i][col] == 'Q') return false;
    }
    for (int i = 0; i < 8; i++) {
        if (row + i < 8 && col + i < 8 && board[row + i][col + i] == 'Q') return false;
        if (row - i >= 0 && col - i >= 0 && board[row - i][col - i] == 'Q') return false;
        if (row + i < 8 && col - i >= 0 && board[row + i][col - i] == 'Q') return false;
        if (row - i >= 0 && col + i < 8 && board[row - i][col + i] == 'Q') return false;
    }
    return true;
}

int totalNumberOfWays(vector<string> &board, int row) {
    if (row == 8) {
        return 1;
    }
    int count = 0;
    for (int i = 0; i < 8; i++) {
        // If the cell is empty and it is safe to place a queen there, then place a queen there and move to the next row. Idea from N-Queens problem.
        if (board[row][i] == '.' && isSafe(board, row, i)) {
            board[row][i] = 'Q';
            count += totalNumberOfWays(board, row + 1);
            board[row][i] = '.';
        }
    }
    return count;
}

int main() {
    vector<string> board(8);
    for (int i = 0; i < 8; i++) {
        cin >> board[i];
    }
    cout << totalNumberOfWays(board, 0);
}