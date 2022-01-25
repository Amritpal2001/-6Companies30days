int equalPartition(int N, int arr[])
{
    // code here
    int sum = 0;
    for (int i = 0; i < N; i++)
        sum += arr[i];
    if (sum % 2)
        return 0;
    sum = sum / 2;
    bool dp[sum + 1] = {false};
    dp[0] = true;
    for (int i = 0; i < N; i++)
    {
        for (int j = sum; j > 0; j--)
        {
            if (j >= arr[i])
                dp[j] = dp[j] || dp[j - arr[i]];
        }
    }
    return dp[sum];
}