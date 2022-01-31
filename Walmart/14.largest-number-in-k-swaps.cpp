void helper(string &str, int k, int index, string &res)
{
    if (k == 0 || index >= str.size())
        return;
    int n = str.size();
    char max_char = str[index];
    for (int i = index + 1; i < n; i++)
    {
        if (max_char < str[i])
            max_char = str[i];
    }
    if (max_char == str[index])
        helper(str, k, index + 1, res);
    else
    {
        for (int i = n - 1; i >= index; i--)
        {
            if (str[i] == max_char)
            {
                swap(str[i], str[index]);
                if (res < str)
                    res = str;
                helper(str, k - 1, index + 1, res);
                swap(str[i], str[index]);
            }
        }
    }
}

//Function to find the largest number after k swaps.
string findMaximumNum(string str, int k)
{
    // code here.
    string res = str;
    helper(str, k, 0, res);
    return res;
}