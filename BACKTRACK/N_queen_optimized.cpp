#include <bits/stdc++.h>
using namespace std;

void solve(int col, vector<string> &board, vector<vector<string>> &ans, vector<int> &leftRow, vector<int> &upperDaigonal,
           vector<int> &lowerDiagonal, int n)
{
    if (col == n)
    {
        ans.push_back(board);
        return;
    }

    for (int row = 0; row < n; row++)
    {
        if (leftRow[row] == 0 && lowerDiagonal[row + col] == 0 && upperDaigonal[n - 1 + col - row] == 0)
        {
            board[row][col] = 'Q';
            leftRow[row] = 1;
            lowerDiagonal[row + col] = 1;
            upperDaigonal[n - 1 + col - row] = 1;

            solve(col + 1, board, ans, leftRow, upperDaigonal, lowerDiagonal, n);
            board[row][col] = '.';
            leftRow[row] = 0;
            lowerDiagonal[row + col] = 0;
            upperDaigonal[n - 1 + col - row] = 0;
        }
    }
}

//left diagonal -> (row - column + (n-1))
//right diagonal -> (row + column)

vector<vector<string>> solveNqueen(int n)
{
    vector<vector<string>> ans;
    vector<string> board(n);
    string s(n, '.');
    for (int i = 0; i < n; i++)
    {
        board[i] = s;
    }

    vector<int> leftRow(n, 0);
    vector<int> upperDaigonal(2 * n - 1, 0);
    vector<int> lowerDiagonal(2 * n - 1, 0);

    solve(0, board, ans, leftRow, upperDaigonal, lowerDiagonal, n);
    return ans;
}

int main()
{
    int n;
    cin >> n;
    vector<vector<string>> s = solveNqueen(n);

    // Displaying the 2D vector
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s[i].size(); j++)
            cout << s[i][j] << " ";
        cout << endl;
    }
    return 0;
}