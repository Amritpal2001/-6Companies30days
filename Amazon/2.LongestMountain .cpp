int longestMountain(vector<int> &arr)
{
    int n = arr.size();
    int res = 0;
    int start = 0;
    int i = 1;
    while (i < n)
    {
        if (arr[i] > arr[i - 1])
        {
            start = i - 1;
            while (i < n && arr[i - 1] < arr[i])
                i++;
            //                 if i-1 is the peak
            if (i < n && arr[i - 1] > arr[i] && arr[i - 1] > arr[i - 2])
            {
                while (i < n && arr[i - 1] > arr[i])
                    i++;
                res = max(res, i - start);
            }
        }
        else
            i++;
    }
    return res;
}