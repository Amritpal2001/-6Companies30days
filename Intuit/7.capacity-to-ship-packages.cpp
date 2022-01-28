bool check(vector<int> &weights, int days, int target)
{
    int n = weights.size();
    int temp = 0;
    int sum = 0;
    for (auto i : weights)
    {
        if (sum + i > target)
        {
            temp++;
            sum = i;
        }
        else
            sum += i;
    }
    if (temp < days)
        return true;
    return false;
}

int shipWithinDays(vector<int> &weights, int days)
{
    int n = weights.size();
    int h = 0;
    int l = INT_MIN;
    for (auto i : weights)
    {
        h += i;
        l = max(l, i);
    }
    int res = h;
    while (l <= h)
    {
        int mid = (l + h) >> 1;
        if (check(weights, days, mid))
        {
            res = min(res, mid);
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}