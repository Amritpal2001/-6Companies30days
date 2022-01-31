struct cmp
{
    bool operator()(string &a, string &b)
    {
        if (a.size() != b.size())
            return a.size() > b.size();
        return a > b;
    }
};

string kthLargestNumber(vector<string> &nums, int k)
{
    int n = nums.size();
    priority_queue<string, vector<string>, cmp> minh(nums.begin(), nums.begin() + k);
    for (int i = k; i < n; i++)
    {
        minh.push(nums[i]);
        minh.pop();
    }
    return minh.top();
}