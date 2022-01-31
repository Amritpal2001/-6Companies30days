int dp[201][201];
int helper(int s, int e)
{
    if (s >= e)
        return 0;
    if (dp[s][e] != -1)
        return dp[s][e];
    int res = INT_MAX;
    for (int i = s; i <= e; i++)
    {
        int temp = max(helper(s, i - 1), helper(i + 1, e)) + i;
        res = min(res, temp);
    }
    return dp[s][e] = res;
}

int getMoneyAmount(int n)
{
    memset(dp, -1, sizeof(dp));
    return helper(1, n);
}