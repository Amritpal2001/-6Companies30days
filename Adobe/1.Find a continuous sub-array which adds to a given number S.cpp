vector<int> subarraySum(int arr[], int n, long long s)
{
    // Your code here
    vector<int> res;
    int i = 0, j = 0;
    long long sum = 0;
    while (j < n)
    {
        sum += arr[j];
        if (sum > s)
        {
            while (i <= j && sum > s)
            {
                sum -= arr[i];
                i++;
            }
        }
        if (sum == s)
        {
            res.push_back(i + 1);
            res.push_back(j + 1);
            return res;
        }
        j++;
    }
    res.push_back(-1);
    return res;
}