vector<string> generate(int N)
{
    // Your code here
    vector<string> res;
    queue<string> q;
    q.push("1");
    while (N--)
    {
        string temp = q.front();
        q.pop();
        res.push_back(temp);
        q.push(temp + "0");
        q.push(temp + "1");
    }
    return res;
}