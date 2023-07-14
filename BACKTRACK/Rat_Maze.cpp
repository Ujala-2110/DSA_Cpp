#include <bits/stdc++.h>
using namespace std;

int result = 0;

bool isSafe(int i, int j, int n)
{
    return i >= 0 && i < n && j >= 0 && j < n;
}

void RatMaze(vector<vector<int>> &maze, int n, int i, int j, vector<vector<int>> &visited)
{
    if(maze[n-1][n-1]==1)//Destination is blocked
    return;

    if(i==n-1 && j== n-1){
        result++;
        return;
    }

    if(!isSafe(i,j,n)){
        //out of boundary
        return;
    }

    //All above lines are base cases and recursion only

    //All down lines are of backtracking (abondoning the invalid path)

    visited[i][j]=1;
    if (isSafe(i - 1, j, n) && maze[i - 1][j] == 0 && visited[i - 1][j] == 0)
    {
        //Up
        RatMaze(maze, n, i - 1, j, visited);
    }
    if (isSafe(i + 1, j, n) && maze[i + 1][j] == 0 && visited[i + 1][j] == 0)
    {
        //Down
        RatMaze(maze, n, i + 1, j, visited);
    }
    if (isSafe(i, j + 1, n) && maze[i][j + 1] == 0 && visited[i][j + 1] == 0)
    {
        //Right
        RatMaze(maze, n, i, j + 1, visited);
    }
    if (isSafe(i, j - 1, n) && maze[i][j - 1] == 0 && visited[i][j - 1] == 0)
    {
        //Left
        RatMaze(maze, n, i, j - 1, visited);
    }

    visited[i][j] = 0;
}
int main()
{
    int n;
    cin >> n; 
    vector<vector<int>> maze(n, vector<int>(n, 0));
    vector<vector<int>> visited(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            cin >> maze[i][j];
        }

    RatMaze(maze, n, 0, 0, visited);

    cout << result;
    return 0;
}