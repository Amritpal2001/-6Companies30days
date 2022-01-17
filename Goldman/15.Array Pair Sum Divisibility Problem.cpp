bool canPair(vector<int> nums, int k) {
        // Code here.
        unordered_map<int,int> mpp;
        for(auto i : nums){
            mpp[i%k]+=1;
        }
        for(auto i : mpp){
            int key = i.first;
            int val = i.second;
            if(key == 0 && (val&1))
                return false;
            else if(key!=0 && (val != mpp[k-key]))
                return false;
        }   
        return true;
    }