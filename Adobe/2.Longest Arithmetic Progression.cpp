// more time complexity
int lengthOfLongestAP(int A[], int n)
{
    // code here
    if (n <= 2)
        return n;
    int res = 1;
    unordered_map<int, int> mpp[n];
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = A[i] - A[j];
            if (mpp[j].find(diff) == mpp[j].end())
                mpp[i][diff] = 1;
            else
                mpp[i][diff] = 1 + mpp[j][diff];
            res = max(res, mpp[i][diff]);
        }
    }
    return res + 1;
}