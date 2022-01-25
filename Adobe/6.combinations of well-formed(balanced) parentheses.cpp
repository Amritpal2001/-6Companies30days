void helper(int open, int close, string str, vector<string> &res)
{
    if (open == 0 && close == 0)
    {
        res.push_back(str);
        return;
    }
    if (open > 0)
        helper(open - 1, close, str + '(', res);
    if (close > 0 && close > open)
        helper(open, close - 1, str + ')', res);
}

vector<string> AllParenthesis(int n)
{
    // Your code goes here
    vector<string> res;
    helper(n, n, "", res);
    return res;
}