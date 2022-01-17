string colName(long long int n)
{
    // your code here
    string res = "";
    while (n > 0)
    {
        char ch = 'A' + (n - 1) % 26;
        res = ch + res;
        n = (n - 1) / 26;
    }
    return res;
}