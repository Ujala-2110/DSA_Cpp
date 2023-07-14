// A Backtracking program in
// C++ to solve Sudoku problem
#include <bits/stdc++.h>
using namespace std;
#define N 9

bool is_safe(int(grid)[N][N], int val, int x, int y)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[i][y] == val)
            return false;

        if (grid[x][i] == val)
            return false;

        if (grid[3 * (x / 3) + i / 3][3 * (y / 3) + i % 3] == val)
            return false;
    }

    return true;
}


void printGrid(int grid[N][N])
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
            cout << grid[row][col] << " ";
        cout << endl;
    }
}

// bool solve_soduku(int grid[N][N], int i, int j)
// {
//     if (i == N)
//     {
//         return true;
//     }
//     if (j == N)
//     {
//         return solve_soduku(grid, i + 1, 0);
//     }
//     if (grid[i][j] != 0)
//     {
//         return solve_soduku(grid, i, j + 1);
//     }

//     for (int no = 1; no <= 9; no++)
//     {
//         if (is_safe(grid, no, i, j))
//         {
//             grid[i][j] = no;
//             if (solve_soduku(grid, i, j + 1))
//             {
//                 return true;
//             }
//         }
//     }
//     grid[i][j] = 0; //Backtracking step
//     return false;
// }

void solve_soduku(int grid[N][N], int i, int j)
{
    if (i == N)
    {
        printGrid(grid);
        return;
    }

    int ni = 0;
    int nj = 0;

    if (j == N - 1)
    {
        ni = i + 1;
        nj = 0;
    }
    else
    {
        ni = i;
        nj = j + 1;
    }

    if (grid[i][j] != 0)
        solve_soduku(grid, ni, nj);

    else
    {
        for (int no = 1; no <= 9; no++)
        {
            
            if (is_safe(grid, no, i, j))
            {
                grid[i][j] = no;
                solve_soduku(grid, ni, nj);
                grid[i][j] = 0; //Backtracking step
            }
        }
    }
}

void SolveSudoku(int grid[N][N])
{
    solve_soduku(grid, 0, 0);
}


int main()
{
    // 0 means unassigned cells
    int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    // if (SolveSudoku(grid) == true)
    //     printGrid(grid);
    // else
    //     cout << "No solution exists";
    SolveSudoku(grid);

    return 0;
}
