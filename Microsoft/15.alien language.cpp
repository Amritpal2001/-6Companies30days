void dfs_topo(vector<int> adj[], int s, bool visited[], string &res)
{
    visited[s] = true;
    for (auto i : adj[s])
        if (!visited[i])
            dfs_topo(adj, i, visited, res);
    res.push_back(s + 'a');
}

string findOrder(string dict[], int N, int K)
{
    //code here
    vector<int> adj[K];
    for (int i = 1; i < N; i++)
    {
        string s1 = dict[i - 1];
        string s2 = dict[i];
        for (int j = 0; j < min(s1.size(), s2.size()); j++)
        {
            if (s1[j] != s2[j])
            {
                int u = s1[j] - 'a';
                int v = s2[j] - 'a';
                adj[u].push_back(v);
                break;
            }
        }
    }
    string res = "";
    bool visited[K] = {false};
    for (int i = 0; i < K; i++)
        if (!visited[i])
            dfs_topo(adj, i, visited, res);
    reverse(res.begin(), res.end());
    return res;
}