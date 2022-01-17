vector<int> max_of_subarrays(vector<int> arr, int n, int k)
{
    // your code here
    deque<int> dq;
    vector<int> res;
    int i = 0, j = 0;
    while (j < n)
    {
        while (!dq.empty() && dq.back() < arr[j])
            dq.pop_back();
        dq.push_back(arr[j]);
        if (j - i + 1 == k)
        {
            res.push_back(dq.front());
            if (dq.front() == arr[i])
                dq.pop_front();
            i++;
        }
        j++;
    }
    return res;
}