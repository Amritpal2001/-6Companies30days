int NumberOfPath(int a, int b)
{
    //code here
    int r = a - 1;
    int N = a + b - 2;

    double res = 1;

    for (int i = 1; i <= r; i++)
    {
        res = res * (N - r + i) / i;
    }
    return (int)res;
}