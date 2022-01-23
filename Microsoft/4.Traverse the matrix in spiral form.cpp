vector<int> spirallyTraverse(vector<vector<int>> matrix, int r, int c)
{
    // code here
    vector<int> res;
    int top = 0, left = 0, right = c - 1, bottom = r - 1;
    while (top <= bottom && left <= right)
    {
        int i = left;
        if (top <= bottom && left <= right)
            while (i <= right)
                res.push_back(matrix[top][i]), i++;
        top++;
        i = top;

        if (top <= bottom && left <= right)
            while (i <= bottom)
                res.push_back(matrix[i][right]), i++;
        right--;
        i = right;

        if (top <= bottom && left <= right)
            while (i >= left)
                res.push_back(matrix[bottom][i]), i--;
        bottom--;
        i = bottom;

        if (top <= bottom && left <= right)
            while (i >= top)
                res.push_back(matrix[i][left]), i--;
        left++;
    }
    return res;
}