int isValid(vector<vector<int>> mat)
{
    // code here
    bool dp[11];
    for (int i = 0; i < 9; i++)
    {
        memset(dp, false, sizeof(dp));
        for (int j = 0; j < 9; j++)
        {
            if (mat[i][j] == 0 || !dp[mat[i][j]])
                dp[mat[i][j]] = true;
            else
                return 0;
        }
    }

    for (int i = 0; i < 9; i++)
    {
        memset(dp, false, sizeof(dp));
        for (int j = 0; j < 9; j++)
        {
            if (mat[j][i] == 0 || !dp[mat[j][i]])
                dp[mat[j][i]] = true;
            else
                return 0;
        }
    }

    for (int i = 0; i < 7; i += 3)
    {
        for (int j = 0; j < 7; j += 3)
        {
            memset(dp, false, sizeof(dp));
            for (int c1 = 0; c1 < 3; c1++)
            {
                for (int c2 = 0; c2 < 3; c2++)
                {
                    if (mat[i + c1][j + c2] == 0 || !dp[mat[i + c1][j + c2]])
                        dp[mat[i + c1][j + c2]] = true;
                    else
                        return 0;
                }
            }
        }
    }
    return 1;
}