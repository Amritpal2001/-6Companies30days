int helper(Node *root)
{
    if (root == NULL)
        return 0;
    int val = root->data;
    int sum = helper(root->left) + helper(root->right);
    root->data = sum;
    return sum + val;
}

void toSumTree(Node *node)
{
    // Your code here
    helper(node);
}