int minSwaps(vector<vector<int>> &grid)
{
    int n = grid.size();
    int arr[n];
    memset(arr, 0, sizeof(arr));
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (grid[i][j] == 0)
                arr[i]++;
            else
                break;
        }
    }

    int res = 0;
    for (int i = 0; i < n - 1; i++)
    {
        int req = n - i - 1;
        if (arr[i] >= req)
            continue;
        int j = i + 1;
        while (j < n && arr[j] < req)
            j++;
        if (j == n)
            return -1;
        res += j - i;
        for (int k = j - 1; k >= i; k--)
            swap(arr[k], arr[k + 1]);
    }
    return res;
}