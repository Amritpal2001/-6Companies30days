int helper(vector<int> &A, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return A[i];
    if (i + 1 == j)
        return max(A[i], A[j]);
    if (dp[i][j] == -1)
    {
        int start_coin = A[i] + min(helper(A, i + 2, j, dp), helper(A, i + 1, j - 1, dp));
        int end_coin = A[j] + min(helper(A, i + 1, j - 1, dp), helper(A, i, j - 2, dp));
        dp[i][j] = max(start_coin, end_coin);
    }

    return dp[i][j];
}

int maxCoins(vector<int> &A, int n)
{
    //Write your code here
    vector<int> v(n, -1);
    vector<vector<int>> dp(n, v);
    return helper(A, 0, n - 1, dp);
}