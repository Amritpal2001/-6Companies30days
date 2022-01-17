string FirstNonRepeating(string A)
{
    // Code here
    int arr[26] = {0};
    queue<char> q;
    string res = "";
    for (int i = 0; i < A.size(); i++)
    {
        q.push(A[i]);
        arr[A[i] - 'a'] += 1;
        while (!q.empty() && arr[q.front() - 'a'] > 1)
            q.pop();
        if (q.empty())
            res.push_back('#');
        else
            res.push_back(q.front());
    }
    return res;
}