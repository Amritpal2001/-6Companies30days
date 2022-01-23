vector<int> calculateSpan(int price[], int n)
{
    // Your code here
    vector<int> res;
    stack<int> s;
    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && price[s.top()] <= price[i])
            s.pop();
        int span = s.empty() ? i + 1 : i - s.top();
        res.push_back(span);
        s.push(i);
    }
    return res;
}