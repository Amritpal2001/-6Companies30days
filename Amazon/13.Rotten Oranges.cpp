int orangesRotting(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();

    int res = -1;
    queue<pair<int, int>> rotten;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 2)
                rotten.push({i, j});
        }
    }

    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};
    while (!rotten.empty())
    {
        res++;
        int len = rotten.size();
        while (len--)
        {
            int x = rotten.front().first;
            int y = rotten.front().second;
            rotten.pop();
            for (int k = 0; k < 4; k++)
            {
                int i = x + dx[k], j = y + dy[k];
                if (i >= 0 && i < m && j >= 0 && j < n && grid[i][j] == 1)
                {
                    grid[i][j] = 2;
                    rotten.push({i, j});
                }
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == 1)
                return -1;
        }
    }
    if (res == -1)
        return 0;
    return res;
}