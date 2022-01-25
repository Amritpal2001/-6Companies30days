int atoi(string str)
{
    //Your code here
    int res = 0;
    int n = str.size();
    int i = 0;
    if (str[0] == '-')
        i++;
    for (; i < n; i++)
    {
        if (str[i] < '0' || str[i] > '9')
            return -1;
        res = res * 10 + (str[i] - '0');
    }
    if (str[0] == '-')
        return res * -1;
    return res;
}