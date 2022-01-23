bool isPossible(int N, vector<pair<int, int>> &prerequisites)
{
    // Code here
    int dp[N] = {0};
    vector<vector<int>> graph(N);
    for (auto i : prerequisites)
    {
        graph[i.second].push_back(i.first);
        dp[i.first]++;
    }

    queue<int> q;
    for (int i = 0; i < N; i++)
        if (dp[i] == 0)
            q.push(i);

    int count = 0;
    while (!q.empty())
    {
        int temp = q.front();
        q.pop();
        count++;
        for (auto i : graph[temp])
        {
            dp[i]--;
            if (dp[i] == 0)
                q.push(i);
        }
    }
    if (count != N)
        return false;
    return true;
}