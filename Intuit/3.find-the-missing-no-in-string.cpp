int _stoi(string s, int i, int j)
{
    int n = s.size();
    if (j > n)
        return -1;
    int res = 0;
    for (; i < j; i++)
    {
        res = res * 10 + (s[i] - '0');
    }
    return res;
}

int missingNumber(const string &str)
{
    // Code here

    int size = str.size();
    for (int i = 1; i <= 6; i++)
    {
        if (size < i)
            return -1;
        int n = _stoi(str, 0, i);
        int res = -1;
        bool flag = false;
        for (int j = i; j < size; j += 1 + log10(n))
        {

            if (res == -1 && _stoi(str, j, j + 1 + log10(n + 2)) == n + 2)
            {
                res = n + 1;
                n += 2;
            }
            else if (_stoi(str, j, j + 1 + log10(n + 1)) == n + 1)
                n += 1;

            else
            {
                flag = true;
                break;
            }
        }
        if (!flag)
            return res;
    }
    return -1;
}