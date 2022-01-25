#define ll long long int
ll power(int a, ll i, ll mod)
{
    long long val = 1;
    while (i--)
    {
        val *= 5;
        val %= mod;
    }
    return val;
}

int kvowelwords(int N, int K)
{
    ll i, j;
    ll mod = 1000000007;
    ll dp[N + 1][K + 1] = {0};
    ll sum = 1;
    for (i = 1; i <= N; i++)
    {
        dp[i][0] = sum * 21;
        dp[i][0] %= mod;
        sum = dp[i][0];

        for (j = 1; j <= K; j++)
        {
            if (j > i)
                continue;
            else if (j == i)
                dp[i][j] = power(5, i, mod);
            else
                dp[i][j] = dp[i - 1][j - 1] * 5;

            dp[i][j] %= mod;

            sum += dp[i][j];
            sum %= mod;
        }
    }
    return sum;
}