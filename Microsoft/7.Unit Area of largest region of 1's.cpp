void DFS(vector<vector<int>> &grid, vector<vector<bool>> &visited, int n, int m, int i, int j, int &res)
{
    if (i >= n || j >= m || i < 0 || j < 0 || grid[i][j] == 0 || visited[i][j])
        return;
    visited[i][j] = true;
    res++;
    static int x[8] = {0, 1, 1, 1, 0, -1, -1, -1};
    static int y[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
    for (int q = 0; q < 8; q++)
        DFS(grid, visited, n, m, i + x[q], j + y[q], res);
}

int findMaxArea(vector<vector<int>> &grid)
{
    // Code here
    int n = grid.size();
    int m = grid[0].size();
    vector<bool> temp(m, false);
    vector<vector<bool>> visited(n, temp);
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] != 0 && !visited[i][j])
            {
                int temp_res = 0;
                DFS(grid, visited, n, m, i, j, temp_res);
                res = max(res, temp_res);
            }
        }
    }
    return res;
}