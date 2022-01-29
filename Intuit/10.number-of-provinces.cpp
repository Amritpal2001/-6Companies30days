void DFS(vector<vector<int>> &isConnected, vector<bool> &visited, int s, int n)
{
    visited[s] = true;
    for (int i = 0; i < n; i++)
    {
        if (isConnected[s][i] == 1 && !visited[i])
            DFS(isConnected, visited, i, n);
    }
}

int findCircleNum(vector<vector<int>> &isConnected)
{
    int n = isConnected.size();
    vector<bool> visited(n, false);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            res++;
            DFS(isConnected, visited, i, n);
        }
    }
    return res;
}