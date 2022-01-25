string nextPalin(string N)
{
    //complete the function here
    int n = N.size();
    if (n <= 3)
        return "-1";
    n = n / 2;
    int i = n - 2;
    while (i >= 0 && N[i] >= N[i + 1])
        i--;
    if (i >= 0)
    {
        int j = n - 1;
        while (j > i && N[i] >= N[j])
            j--;
        swap(N[i], N[j]);
        reverse(N.begin() + i + 1, N.begin() + n);
        i = 0;
        j = N.size() - 1;
        while (i < j)
        {
            N[j] = N[i];
            i++;
            j--;
        }
        return N;
    }
    else
    {
        return "-1";
    }
}