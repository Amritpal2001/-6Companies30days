// TLE approach
double dis(vector<int> &p1, vector<int> &p2)
{
    double x = pow(p1[0] - p2[0], 2);
    double y = pow(p1[1] - p2[1], 2);
    return sqrt(x + y);
}

int numberOfBoomerangs(vector<vector<int>> &points)
{
    int n = points.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            double val = dis(points[i], points[j]);
            for (int k = 0; k < n; k++)
            {
                if (i == k || j == k)
                    continue;
                if (val == dis(points[i], points[k]))
                    res++;
            }
        }
    }
    return res;
}

// Optimized
double dis(vector<int> &p1, vector<int> &p2)
{
    int x = pow(p1[0] - p2[0], 2);
    int y = pow(p1[1] - p2[1], 2);
    return x + y;
}

int numberOfBoomerangs(vector<vector<int>> &points)
{
    int n = points.size();
    int res = 0;
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j == i)
                continue;
            mpp[dis(points[i], points[j])]++;
        }
        for (auto i : mpp)
        {
            int temp = i.second;
            res += temp * (temp - 1);
        }
        mpp.clear();
    }
    return res;
}