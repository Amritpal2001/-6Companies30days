int LIS(vector<int> arr)
{
    int n = arr.size();
    if (n <= 1)
        return n;
    vector<int> dp;
    dp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        int lb = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
        if (lb == dp.size())
            dp.push_back(arr[i]);
        else
            dp[lb] = arr[i];
    }
    return dp.size();
}

int minInsAndDel(int A[], int B[], int N, int M)
{
    // code here
    int res = 0;
    unordered_set<int> ss;
    for (int i = 0; i < M; i++)
        ss.insert(B[i]);
    vector<int> arr;
    for (int i = 0; i < N; i++)
    {
        if (ss.find(A[i]) != ss.end())
            arr.push_back(A[i]);
        else
            res++;
    }
    int n = arr.size();
    int lis = LIS(arr);
    return res + n - lis + M - lis;
}