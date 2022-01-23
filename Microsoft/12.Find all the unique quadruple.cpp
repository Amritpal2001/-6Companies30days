vector<vector<int>> fourSum(vector<int> &arr, int k)
{
    // Your code goes here
    sort(arr.begin(), arr.end());
    int n = arr.size();
    vector<vector<int>> res;
    for (int i = 0; i < n - 3; i++)
    {
        for (int j = i + 1; j < n - 2; j++)
        {
            int target = k - arr[i] - arr[j];
            int l = j + 1;
            int h = n - 1;
            while (l < h)
            {
                int two_sum = arr[l] + arr[h];
                if (two_sum < target)
                    l++;
                else if (two_sum > target)
                    h--;
                else
                {
                    vector<int> temp(4);
                    temp[0] = arr[i];
                    temp[1] = arr[j];
                    temp[2] = arr[l];
                    temp[3] = arr[h];
                    res.push_back(temp);
                    while (l < h && arr[l] == temp[2])
                        l++;
                    while (l < h && arr[h] == temp[3])
                        h--;
                }
            }
            while (j < n - 2 && arr[j + 1] == arr[j])
                j++;
        }
        while (i < n - 3 && arr[i + 1] == arr[i])
            i++;
    }
    return res;
}