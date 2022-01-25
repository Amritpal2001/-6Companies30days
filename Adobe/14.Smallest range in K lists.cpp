// TLE Solution on LeetCode
vector<int> smallestRange(vector<vector<int>> &nums)
{
    int n = nums.size();
    vector<int> res(2, -1);
    int rres = INT_MAX;
    vector<int> arr(n, 0);
    while (true)
    {
        int min_val = INT_MAX, max_val = INT_MIN;
        int min_i;
        for (int k = 0; k < n; k++)
        {
            if (nums[k][arr[k]] < min_val)
            {
                min_val = nums[k][arr[k]];
                min_i = k;
            }
            if (nums[k][arr[k]] > max_val)
            {
                max_val = nums[k][arr[k]];
            }
        }
        if (rres > max_val - min_val)
        {
            rres = max_val - min_val;
            res[0] = min_val;
            res[1] = max_val;
        }
        arr[min_i]++;
        if (arr[min_i] >= nums[min_i].size())
            break;
    }
    return res;
}

// Optimized using priority queue

typedef pair<int, pair<int, int>> pi;
vector<int> smallestRange(vector<vector<int>> &nums)
{
    int n = nums.size();
    vector<int> res(2);
    int val_res = INT_MAX;
    int max_val = INT_MIN;
    priority_queue<pi, vector<pi>, greater<pi>> pq;
    for (int i = 0; i < n; i++)
    {
        pq.push({nums[i][0], {i, 0}});
        max_val = max(max_val, nums[i][0]);
    }

    while (true)
    {
        pi temp_pair = pq.top();
        pq.pop();
        int min_val = temp_pair.first;
        int i_val = temp_pair.second.first;
        int j_val = temp_pair.second.second;
        int diff = max_val - min_val;
        if (val_res > diff)
        {
            val_res = diff;
            res[0] = min_val;
            res[1] = max_val;
        }
        j_val++;
        if (j_val >= nums[i_val].size())
            break;
        pq.push({nums[i_val][j_val], {i_val, j_val}});
        max_val = max(max_val, nums[i_val][j_val]);
    }
    return res;
}