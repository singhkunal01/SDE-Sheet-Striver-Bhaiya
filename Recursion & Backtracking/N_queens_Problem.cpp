#include <bits/stdc++.h>
using namespace std;
//this function is used to check whether the place is safe or not means no either queen can attack over another
bool isSafeToPlace(int row, int col, vector<string> &board, int n) {

	/* for each queen we have to check 8 directions to get attacked but
	if we observe then we get total 3 directions to check safe place
	WHAT ARE THESE DIRECTIONS ??
	1.Upper Left diagonal (row-- , col--)
	2. Left area of same row (east)(row, col--)
	3. Lower Left diagonal(row++, col--) */
	int copyRow = row, copyCol = col;
//checking the 1 direction i.e., TOP-LEFT area of the chessBoard from the current Box (moving upside)
	while (row >= 0 and col >= 0) {
		if (board[row][col] == 'Q') return false;
		row--, col--;
	}

//checking the 2 direction i.e., LEFT side area (Same row in the current Box of the column)
	row = copyRow, col = copyCol;
	while (col >= 0) {
		if (board[row][col] == 'Q') return false;
		col--;
	}

//checking the 3 direction i.e, BOTTOM-LEFT area of the chessBoard from the current Box (Movig downwards)
	row = copyRow, col = copyCol;
	while (row < n and col >= 0) {
		if (board[row][col] == 'Q') return false;
		row++, col--;
	}
	return true;
}

//this function is used to place the queens on safe places and returns the possible answers
void solveProblem(int col, vector<string> &board, vector<vector<string>> &final, int n) {
//base case is simple whenever we reach out of the columns([0,n-1]) then return
	if (col == n) {
		final.push_back(board);
		return;
	}
	/* now iterate over rows for each columns and check whether the place for
	placing queen is safe or not if yes then place and call the same function*/
	for (int row = 0; row < n; row++) {
		if (isSafeToPlace(row, col, board, n)) {
//it means it is safe to place so
			board[row][col] = 'Q';
			solveProblem(col + 1, board, final, n);
			board[row][col] = '.';//removing the queen where we placed to check the possible cases using backtracking
		}
	}
}

//main function which returns the final answer of checkBoard
vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> final;
	vector<string> board(n);
	string s(n, '.');
	for (int i = 0; i < n; i++)board[i] = s;
	solveProblem(0, board , final , n);
	return final;
}
