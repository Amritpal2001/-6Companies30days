int divide(int dividend, int divisor)
{
    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;
    long a = labs(dividend), b = labs(divisor);
    long res = 0;
    while (a >= b)
    {
        long temp = b, m = 1;
        while ((a - (temp << 1)) > 0)
        {
            temp <<= 1;
            m <<= 1;
        }
        res += m;
        a -= temp;
    }
    return (dividend > 0) == (divisor > 0) ? res : -res;
}