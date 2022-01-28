bool visited[101][101];
bool helper(vector<vector<char>> &board, string &word, int index, int i, int j)
{
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || visited[i][j] || board[i][j] != word[index])
        return false;
    if (index == word.size() - 1 && board[i][j] == word[index])
        return true;
    visited[i][j] = true;
    return helper(board, word, index + 1, i + 1, j) || helper(board, word, index + 1, i, j + 1) || helper(board, word, index + 1, i - 1, j) || helper(board, word, index + 1, i, j - 1);
}

bool isWordExist(vector<vector<char>> &board, string word)
{
    // Code here
    int n = board.size();
    int m = board[0].size();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == word[0])
            {
                memset(visited, false, sizeof(visited));
                if (helper(board, word, 0, i, j))
                    return true;
            }
        }
    }
    return false;
}