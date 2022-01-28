// Using recursion, TLE
// Here consider that correct answer will come from the further recursion call
int helper(vector<int> &nums, int m, int index)
{
    if (m == 0 || index >= nums.size())
        return 0;
    int n = nums.size();
    int res = INT_MAX;
    int sum = 0;

    if (m == 1)
    {
        for (int i = index; i < n; i++)
            sum += nums[i];
        return sum;
    }
    for (int i = index; i < n - m + 1; i++)
    {
        sum += nums[i];
        int temp = helper(nums, m - 1, i + 1);
        temp = max(sum, temp);
        res = min(res, temp);
    }
    return res;
}

int splitArray(vector<int> &nums, int m)
{
    return helper(nums, m, 0);
}

// Using Memoization
int dp[1001][51];

int helper(vector<int> &nums, int m, int index)
{

    int n = nums.size();
    int res = INT_MAX;
    int sum = 0;

    if (m == 1)
    {
        for (int i = index; i < n; i++)
            sum += nums[i];
        return sum;
    }
    for (int i = index; i < n - m + 1; i++)
    {
        sum += nums[i];
        int temp;
        if (dp[i + 1][m - 1] != -1)
            temp = dp[i + 1][m - 1];
        else
            dp[i + 1][m - 1] = temp = helper(nums, m - 1, i + 1);
        temp = max(sum, temp);
        res = min(res, temp);
    }
    return res;
}

int splitArray(vector<int> &nums, int m)
{
    memset(dp, -1, sizeof(dp));
    return helper(nums, m, 0);
}




// Using Binary Search
// Here we chose lower value as max of array, so no need to check in check function that nums[i] > target;
bool check(vector<int> &nums, int m, int target)
{
    int n = nums.size();
    int temp = 0;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + nums[i] > target)
        {
            temp++;
            sum = nums[i];
        }
        else
            sum += nums[i];
    }
    if (temp + 1 <= m)
        return true;
    return false;
}

int splitArray(vector<int> &nums, int m)
{
    int sum = 0;
    int l = INT_MIN;
    for (auto i : nums)
    {
        sum += i;
        l = max(l, i);
    }
    int h = sum;
    int res = sum;
    while (l <= h)
    {
        int mid = (l + h) >> 1;
        if (check(nums, m, mid))
        {
            res = min(res, mid);
            h = mid - 1;
        }
        else
            l = mid + 1;
    }
    return res;
}