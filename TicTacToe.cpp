#include <bits/stdc++.h>
using namespace std;

const int n = 3;
const int m = 3;
vector<vector<char>> v(n, vector<char>(m, ' '));

void printBoard(const vector<vector<char>> &v)
{
	cout << "-------------\n";
	for (int i = 0; i < n; i++)
	{
		cout << "|";
		for (int j = 0; j < m; j++)
		{
			cout << " " << v[i][j] << " |";
		}
		cout << "\n-------------\n";
	}
}
bool win(const vector<vector<char>> &v, int row, int col)
{
	if (v[row][col] == ' ')
	{
		return false;
	}
	bool d1 = false, d2 = false, r = true, c = true;
	for (int j = 0; j < m; j++)
	{
		if (v[row][col] != v[row][j])
		{
			r = false;
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (v[row][col] != v[i][col])
		{
			c = false;
			break;
		}
	}
	if (row == col)
	{
		d1 = true;
		for (int i = 0; i < n; i++)
		{
			if (v[i][i] != v[row][col])
			{
				d1 = false;
				break;
			}
		}
	}
	if (row + col == n - 1)
	{
		d2 = true;
		for (int i = 0; i < m; i++)
		{
			if (v[i][n - i - 1] != v[row][col])
			{
				d2 = false;
				break;
			}
		}
	}
	return (d1 || d2 || c || r);
}
bool check(int row, int col, const vector<vector<char>> &v)
{
	if (row < 0 || col < 0 || row >= n || col >= m)
	{
		cout << "Invalid\n";
		return false;
	}
	if (v[row][col] != ' ')
	{
		cout << "Occupied\n";
		return false;
	}
	return true;
}
int main()
{
	printBoard(v);
	int player1 = 5, player2 = 4, totalMoves = 9;
	bool won = false;
	while (totalMoves--)
	{
		int row, col;
		while (true)
		{
			if (!(cin >> row >> col))
			{
				cout << "\nInput terminated.\n";
				return 0;
			}
			if (check(row, col, v))
			{
				break;
			}
		}

		if (player1 > player2)
		{
			v[row][col] = 'X';
			if (win(v, row, col))
			{
				printBoard(v);
				cout << "Player1 wins\n";
				won = true;
				break;
			}

			player1--;
		}
		else
		{
			v[row][col] = 'O';
			if (win(v, row, col))
			{
				printBoard(v);
				cout << "Player2 wins\n";
				won = true;
				break;
			}

			player2--;
		}

		printBoard(v);
	}
	if (!won)
	{
		cout << "It's a draw!\n";
	}
	return 0;
}
