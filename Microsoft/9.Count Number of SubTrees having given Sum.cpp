int helper(Node *root, int X, int &res)
{
    if (root == NULL)
        return 0;
    int l = helper(root->left, X, res);
    int r = helper(root->right, X, res);

    int sum = l + r + root->data;
    if (sum == X)
        res++;
    return sum;
}

int countSubtreesWithSumX(Node *root, int X)
{
    // Code here
    int res = 0;
    helper(root, X, res);
    return res;
}
