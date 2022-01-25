vector<string> res(2);
unordered_map<string, int> mpp;
int max_val = INT_MIN;
for (int i = 0; i < n; i++)
{
    mpp[arr[i]] += 1;
}
for (auto i : mpp)
{
    string key = i.first;
    int val = i.second;
    if (val > max_val)
    {
        max_val = val;
        res[0] = key;
        res[1] = to_string(val);
    }
    else if (val == max_val && key < res[0])
        res[0] = key;
}
return res;