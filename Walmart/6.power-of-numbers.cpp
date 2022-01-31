long long power(int N, int R)
{
    //Your code here
    long long res = 1;
    long long n = N;
    while (R > 0)
    {
        if (R % 2 == 0)
        {
            n = n * n;
            n = n % 1000000007;
            R = R / 2;
        }
        else
        {
            res = res * n;
            res = res % 1000000007;
            R = R - 1;
        }
    }
    return res;
}