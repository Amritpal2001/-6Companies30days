vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    int n = numCourses;
    vector<int> adj[n];
    vector<int> res;
    for (auto i : prerequisites)
    {
        adj[i[1]].push_back(i[0]);
    }
    int arr[n];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++)
    {
        for (auto j : adj[i])
            arr[j]++;
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
        if (arr[i] == 0)
            q.push(i);

    int count = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        res.push_back(x);
        count++;
        for (auto i : adj[x])
        {
            arr[i]--;
            if (arr[i] == 0)
                q.push(i);
        }
    }
    if (count == n)
        return res;
    return {};
}