void dfs(vector<vector<int>> &heights, vector<vector<bool>> &visited, int x, int y, int prev)
{
    int m = heights.size();
    int n = heights[0].size();

    if (x < 0 || x >= m || y < 0 || y >= n || visited[x][y] || heights[x][y] < prev)
        return;

    visited[x][y] = true;

    int dx[] = {1, 0, -1, 0};
    int dy[] = {0, 1, 0, -1};

    for (int i = 0; i < 4; i++)
        dfs(heights, visited, x + dx[i], y + dy[i], heights[x][y]);
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    int m = heights.size();
    int n = heights[0].size();

    vector<vector<int>> res;
    vector<vector<bool>> pac(m, vector<bool>(n, false));
    vector<vector<bool>> atl(m, vector<bool>(n, false));

    for (int i = 0; i < m; i++)
    {
        dfs(heights, pac, i, 0, heights[i][0]);
        dfs(heights, atl, i, n - 1, heights[i][n - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        dfs(heights, pac, 0, i, heights[0][i]);
        dfs(heights, atl, m - 1, i, heights[m - 1][i]);
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pac[i][j] && atl[i][j])
            {
                res.push_back({i, j});
            }
        }
    }

    return res;
}