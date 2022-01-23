int minDifference(int arr[], int n)
{
    // Your code goes here
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum += arr[i];
    bool dp[sum + 1] = {false};
    dp[0] = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = sum; j > 0; j--)
        {
            if (j >= arr[i])
                dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    int res = INT_MAX;
    for (int i = 0; i <= sum / 2; i++)
    {
        if (dp[i])
            res = min(res, abs(sum - 2 * i));
    }
    return res;
}