void serialize(Node *root, vector<int> &v)
{
    if (root == NULL)
    {
        v.push_back(-1);
        return;
    }
    v.push_back(root->data);
    serialize(root->left, v);
    serialize(root->right, v);
}

vector<int> serialize(Node *root)
{
    //Your code here
    vector<int> res;
    serialize(root, res);
    return res;
}

//Function to deserialize a list and construct the tree.

Node *deSerialize(vector<int> &A, int &index)
{
    if (index == A.size())
        return NULL;
    int val = A[index++];
    if (val == -1)
        return NULL;
    Node *root = new Node(val);
    root->left = deSerialize(A, index);
    root->right = deSerialize(A, index);
    return root;
}

Node *deSerialize(vector<int> &A)
{
    //Your code here
    int index = 0;
    return deSerialize(A, index);
}