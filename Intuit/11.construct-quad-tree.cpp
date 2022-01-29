int check(vector<vector<int>> &grid, int t, int l, int size)
{
    int curr = grid[t][l];
    for (int i = t; i < t + size; i++)
        for (int j = l; j < l + size; j++)
            if (grid[i][j] != curr)
                return -1;
    return curr;
}

Node *helper(vector<vector<int>> &grid, int t, int l, int size)
{
    if (size == 1)
    {
        Node *temp = new Node(grid[t][l], true);
        return temp;
    }

    int x = check(grid, t, l, size);
    if (x != -1)
        return new Node(x, true);
    Node *root = new Node(1, false);

    x = check(grid, t, l, size / 2);
    if (x != -1)
        root->topLeft = new Node(x, true);
    else
        root->topLeft = helper(grid, t, l, size / 2);

    x = check(grid, t, l + size / 2, size / 2);
    if (x != -1)
        root->topRight = new Node(x, true);
    else
        root->topRight = helper(grid, t, l + size / 2, size / 2);

    x = check(grid, t + size / 2, l, size / 2);
    if (x != -1)
        root->bottomLeft = new Node(x, true);
    else
        root->bottomLeft = helper(grid, t + size / 2, l, size / 2);

    x = check(grid, t + size / 2, l + size / 2, size / 2);
    if (x != -1)
        root->bottomRight = new Node(x, true);
    else
        root->bottomRight = helper(grid, t + size / 2, l + size / 2, size / 2);

    return root;
}

Node *construct(vector<vector<int>> &grid)
{
    int n = grid.size();
    return helper(grid, 0, 0, n);
}