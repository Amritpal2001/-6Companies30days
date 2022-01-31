vector<int> recoverArray(int n, vector<int> &s)
{
    vector<int> res;
    sort(s.begin(), s.end());
    while (s.size() > 1)
    {
        vector<int> left, right;
        int num = s[1] - s[0], is_zero = false;
        for (int i = 0, j = 0; i < s.size(); ++i)
            if (s[i] != INT_MIN)
            {
                is_zero |= s[i] == 0;
                left.push_back(s[i]);
                right.push_back(s[i] + num);
                for (j = max(j + 1, i + 1); s[j] != s[i] + num; ++j)
                    ;
                s[j] = INT_MIN;
            }
        res.push_back(num * (is_zero ? 1 : -1));
        swap(s, is_zero ? left : right);
    }
    return res;
}