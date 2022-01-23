void dfs(vector<int> adj[], int c, int d, bool vis[], int s)
{
    vis[s] = true;
    for (auto i : adj[s])
    {
        if (s == c && i == d)
            continue;
        if (!vis[i])
            dfs(adj, c, d, vis, i);
    }
}

int isBridge(int V, vector<int> adj[], int c, int d)
{
    // Code here
    bool vis[V] = {false};
    dfs(adj, c, d, vis, c);
    return (!vis[d]);
}