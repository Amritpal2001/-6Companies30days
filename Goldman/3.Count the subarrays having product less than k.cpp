int countSubArrayProductLessThanK(const vector<int>& a, int n, long long k) {
        int res=0;
        long long pdt = 1;
        int i=0,j=0;
        while(i<n && j<n){
            pdt*= a[j];
            while(i<=j && pdt >=k){ 
                pdt/=a[i];
                i++;
            }
            res+=j-i+1;
            j++;
        }
        return res;
    }