vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string> > res;
        unordered_map<string, vector<int>> mpp;
        vector<string> temp_list = string_list;
        for(int i=0;i<temp_list.size();i++)
            sort(temp_list[i].begin(), temp_list[i].end());
        
        for(int i=0;i<temp_list.size();i++)
        {
            string str = temp_list[i];
            if(mpp.find(str) == mpp.end())
            {
                vector<int> v;
                v.push_back(i);
                mpp[str] = v;
            }
            else
                mpp[str].push_back(i);
        }
        
        for(auto i : mpp)
        {
            vector<string> vec;
            for(auto j : i.second)
                vec.push_back(string_list[j]);
            res.push_back(vec);
        }
        return res;
    }

