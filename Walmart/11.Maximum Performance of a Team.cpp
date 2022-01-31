//     Here we first select total k workers, i.e. we try every efficency till k workers are selected. Then afterwards we greedily select worker only if it will increase overall result.
static bool cmp(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.first > p2.first;
}

int maxPerformance(int n, vector<int> &speed, vector<int> &efficiency, int k)
{
    vector<pair<int, int>> arr;
    for (int i = 0; i < n; i++)
        arr.push_back({efficiency[i], speed[i]});
    sort(arr.begin(), arr.end(), cmp);
    priority_queue<int, vector<int>, greater<int>> pq;
    long res = 0, sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += arr[i].second;
        pq.push(arr[i].second);
        res = max(res, sum * arr[i].first);
    }
    for (int i = k; i < n; i++)
    {
        if (pq.top() < arr[i].second)
        {
            sum -= pq.top();
            pq.pop();
            sum += arr[i].second;
            pq.push(arr[i].second);
            res = max(res, arr[i].first * sum);
        }
    }
    return res % int(1e9 + 7);
}