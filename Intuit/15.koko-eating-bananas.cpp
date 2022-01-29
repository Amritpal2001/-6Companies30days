bool check(vector<int> &piles, int h, int t)
{
    int res = 0;
    for (auto i : piles)
    {
        res += i / t;
        if (i % t)
            res += 1;
    }
    if (res <= h)
        return true;
    return false;
}

int minEatingSpeed(vector<int> &piles, int h)
{
    int n = piles.size();
    int l = 1;
    int e = INT_MIN;
    for (auto i : piles)
        e = max(e, i);
    int res = INT_MAX;
    while (l <= e)
    {
        int mid = (l + e) >> 1;
        if (check(piles, h, mid))
        {
            res = min(res, mid);
            e = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}