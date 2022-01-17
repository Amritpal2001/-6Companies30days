vector<vector<string>> displayContacts(int n, string contact[], string s)
{
    // code here
    vector<vector<string>> res;
    bool not_consider[n] = {false};
    for (int i = 0; i < s.size(); i++)
    {
        char search = s[i];
        set<string> ss;
        for (int j = 0; j < n; j++)
        {
            if (contact[j].size() > i && !not_consider[j] && contact[j][i] == search)
                ss.insert(contact[j]);
            else
                not_consider[j] = true;
        }
        vector<string> temp(ss.begin(), ss.end());
        if (temp.size() == 0)
            temp.push_back("0");
        res.push_back(temp);
    }
    return res;
}