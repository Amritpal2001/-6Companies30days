vector<int> find3Numbers(vector<int> arr, int N)
{
    // Your code here
    int a = INT_MAX, b = INT_MAX, min_val = INT_MAX;
    vector<int> res;
    for (int i = 0; i < N; i++)
    {
        if (min_val > arr[i])
            min_val = arr[i];
        else if (arr[i] > min_val && arr[i] < b)
        {
            a = min_val;
            b = arr[i];
        }
        else if (arr[i] > a && arr[i] > b)
        {
            res.push_back(a);
            res.push_back(b);
            res.push_back(arr[i]);
            return res;
        }
    }
    return res;
}