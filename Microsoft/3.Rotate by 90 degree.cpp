void rotate(vector<vector<int>> &matrix)
{
    // Your code goes here
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < m; j++)
            swap(matrix[i][j], matrix[j][i]);
    }

    int i = 0, j = n - 1;
    while (i < j)
        swap(matrix[i], matrix[j]), i++, j--;
}