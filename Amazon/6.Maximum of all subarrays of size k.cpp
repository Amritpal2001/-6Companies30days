vector<int> max_of_subarrays(int *arr, int n, int k)
{
    // your code here
    vector<int> res;
    deque<int> q;
    int i = 0, j = 0;
    while (j < n)
    {
        while (!q.empty() && q.back() < arr[j])
            q.pop_back();
        q.push_back(arr[j]);
        if (j - i + 1 == k)
        {
            res.push_back(q.front());
            if (q.front() == arr[i])
                q.pop_front();
            i++;
        }
        j++;
    }
    return res;
}