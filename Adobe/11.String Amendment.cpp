string amendSentence(string s)
{
    // your code here
    string res = "";
    res.push_back(tolower(s[0]));
    for (int i = 1; i < s.size(); i++)
    {
        if (s[i] >= 'A' && s[i] <= 'Z')
        {
            res.push_back(' ');
            res.push_back(tolower(s[i]));
        }
        else
            res.push_back(s[i]);
    }
    return res;
}