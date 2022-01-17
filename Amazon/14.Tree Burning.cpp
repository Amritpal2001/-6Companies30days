Node *getParents(Node *root, int target, unordered_map<Node *, Node *> &mpp)
{
    if (root == NULL)
        return NULL;
    queue<Node *> q;
    q.push(root);
    Node *tgt = NULL;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            if (temp->data == target)
            {
                tgt = temp;
            }
            q.pop();
            if (temp->left)
            {
                mpp[temp->left] = temp;
                q.push(temp->left);
            }
            if (temp->right)
            {
                mpp[temp->right] = temp;
                q.push(temp->right);
            }
        }
    }
    return tgt;
}

int timeTaken(Node *tgt, unordered_map<Node *, Node *> &mpp)
{
    if (tgt == NULL)
        return 0;
    unordered_map<Node *, int> visited;
    queue<Node *> q;
    q.push(tgt);
    visited[tgt] = 1;
    int res = 0;
    while (!q.empty())
    {
        int size = q.size();
        for (int i = 0; i < size; i++)
        {
            Node *temp = q.front();
            q.pop();
            if (temp->left && !visited[temp->left])
            {
                visited[temp->left] = 1;
                q.push(temp->left);
            }
            if (temp->right && !visited[temp->right])
            {
                visited[temp->right] = 1;
                q.push(temp->right);
            }
            if (mpp[temp] && !visited[mpp[temp]])
            {
                visited[mpp[temp]] = 1;
                q.push(mpp[temp]);
            }
        }
        if (!q.empty())
            res++;
    }
    return res;
}

int minTime(Node *root, int target)
{
    // Your code goes here
    unordered_map<Node *, Node *> mpp;
    Node *tgt = getParents(root, target, mpp);
    return timeTaken(tgt, mpp);
}