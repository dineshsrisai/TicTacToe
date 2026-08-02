#include<bits/stdc++.h>
using namespace std;

const int n = 3;
const int m = 3;
vector<vector<char>> v(n, vector<char>(m, ' '));

void printBoard(const vector<vector<char>>& v) {
	cout << "----------------------------\n";
	for (int i = 0; i < n; i++) {
		cout << "|";
		for (int j = 0; j < m; j++) {
			cout << " " << v[i][j] << " |";
		}
		cout << "\n----------------------------\n";
	}
}

bool win(vector<vector<char>>&v, int row, int col) {
	return false;
}

bool check(int row, int col, const vector<vector<char>> &v) {
	if (row < 0 || col < 0 || row >= n || col >= m) {
		cout << "Invalid\n";
		return false;
	}
	if (v[row][col] != ' ') {
		cout << "Occupied\n";
		return false;
	}
	return true;
}


int main() {
	printBoard(v);
	int player1 = 5, player2 = 4, totalMoves = 9;
	bool won = false;
	while (totalMoves--) {
		int row, col;
		cin >> row >> col;
		while (!check(row, col, v)) {
			cin >> row >> col;
		}
		if (player1 > player2) {
			v[row][col] = 'X';
			if (win(v, row, col)) {
				cout << "Player1 wins\n";
				won = true;
				break;
			}
			player1--;
		} else {
			v[row][col] = 'O';
			if (win(v, row, col)) {
				cout << "Player2 wins\n";
				won = true;
				break;
			}
			player2--;
		}
		printBoard(v);
	}
	printBoard(v);
	if (!won) {
		cout << "It's a draw!\n";
	}
	return 0;
}