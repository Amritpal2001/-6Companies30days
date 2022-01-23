int minSteps(int D)
{
    // code here
    D = abs(D);
    int k = 0;
    while (D > 0)
    {
        k++;
        D -= k;
    }
    return D % 2 == 0 ? k : k + 1 + k % 2;
}