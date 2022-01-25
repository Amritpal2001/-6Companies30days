vector<int> leaders(int a[], int n)
{
    // Code here
    vector<int> res;
    int max_val = a[n - 1];
    for (int i = n - 1; i >= 0; i--)
    {
        if (a[i] >= max_val)
        {
            res.push_back(a[i]);
            max_val = a[i];
        }
    }
    reverse(res.begin(), res.end());
    return res;
}