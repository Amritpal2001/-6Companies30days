void print_brackets(int **dp, int i, int j, char &c, string &res)
{
    if (i == j)
    {
        res.push_back(c);
        c++;
        return;
    }
    res.push_back('(');
    print_brackets(dp, i, dp[j][i], c, res);
    print_brackets(dp, dp[j][i] + 1, j, c, res);
    res.push_back(')');
}

string matrixChainOrder(int p[], int n)
{
    // code here
    int **dp = new int *[n];
    for (int i = 0; i < n; i++)
        dp[i] = new int[n];

    for (int L = 2; L < n; L++)
    {
        for (int i = 1; i <= n - L; i++)
        {
            int j = i + L - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                int temp = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (dp[i][j] > temp)
                {
                    dp[i][j] = temp;
                    dp[j][i] = k;
                }
            }
        }
    }
    string res = "";
    char c = 'A';
    print_brackets(dp, 1, n - 1, c, res);
    return res;
}