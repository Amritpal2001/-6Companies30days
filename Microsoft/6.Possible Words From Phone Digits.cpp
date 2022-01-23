void helper(int a[], int N, vector<string> &res, int index, string ds, vector<string> &vals)
{
    if (index == N)
    {
        res.push_back(ds);
        return;
    }

    string temp = vals[a[index]];
    for (int i = 0; i < temp.size(); i++)
        helper(a, N, res, index + 1, ds + temp[i], vals);
}

//Function to find list of all words possible by pressing given numbers.
vector<string> possibleWords(int a[], int N)
{
    //Your code here
    vector<string> vals = {
        "", "",
        "abc",
        "def",
        "ghi",
        "jkl",
        "mno",
        "pqrs",
        "tuv",
        "wxyz"};

    vector<string> res;
    helper(a, N, res, 0, "", vals);
    return res;
}