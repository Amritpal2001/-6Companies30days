int maxProfit(int K, int N, int A[])
{
    // code here
    if (N == 1)
        return 0;
    int dp[K + 1][N];
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= K; i++)
    {
        int max_diff = INT_MIN;
        for (int j = 1; j < N; j++)
        {
            max_diff = max(max_diff, dp[i - 1][j - 1] - A[j - 1]);
            dp[i][j] = max(dp[i][j - 1], max_diff + A[j]);
        }
    }
    return dp[K][N - 1];
}