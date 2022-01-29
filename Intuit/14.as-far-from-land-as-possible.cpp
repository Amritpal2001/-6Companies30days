int maxDistance(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int res = 0;
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (grid[i][j] == 1)
                q.push({i, j});
    if (q.size() == 0 || q.size() == n * m)
        return -1;

    int x[] = {1, 0, -1, 0};
    int y[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int size = q.size();
        res++;
        while (size--)
        {
            auto [oi, oj] = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int ni = oi + x[i];
                int nj = oj + y[i];
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && grid[ni][nj] == 0)
                    q.push({ni, nj}), grid[ni][nj] = 1;
            }
        }
    }
    return res - 1;
}