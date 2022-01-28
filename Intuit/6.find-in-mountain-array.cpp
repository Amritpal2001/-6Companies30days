int findInMountainArray(int target, MountainArray &mountainArr)
{
    int n = mountainArr.length();
    int peak;
    int l = 0;
    int h = n - 1;
    while (l < h)
    {
        int mid = (l + h) >> 1;
        if (mountainArr.get(mid) < mountainArr.get(mid + 1))
            l = mid + 1;
        else
            h = mid;
    }
    peak = l;
    if (mountainArr.get(peak) == target)
        return peak;
    l = 0;
    h = peak - 1;
    while (l <= h)
    {
        int mid = (l + h) >> 1;
        int val = mountainArr.get(mid);
        if (val == target)
            return mid;
        if (val < target)
            l = mid + 1;
        else
            h = mid - 1;
    }
    l = peak + 1;
    h = n - 1;
    while (l <= h)
    {
        int mid = (l + h) >> 1;
        int val = mountainArr.get(mid);
        if (val == target)
            return mid;
        if (val < target)
            h = mid - 1;
        else
            l = mid + 1;
    }
    return -1;
}