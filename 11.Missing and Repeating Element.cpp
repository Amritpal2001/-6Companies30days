int *findTwoElement(int *arr, int n) {
        // code here
        int * res = new int[2];
        int temp=1;
        for(int i=2;i<=n;i++){
            temp ^= i;
        }
        for(int i=0;i<n;i++)
            temp ^= arr[i];
        
        int set_bit= temp & ~(temp-1);
        
        int set_bucket=0, nonset_bucket=0;
        
        for(int i=0;i<n;i++){
            if(arr[i] & set_bit)
                set_bucket ^= arr[i];
            else
                nonset_bucket ^= arr[i];
        }
        
        for(int i=1; i<=n; i++){
            if(i & set_bit)
                set_bucket ^= i;
            else
                nonset_bucket ^= i;
        }
        for(int i=0; i<n;i++)
        {
            if(nonset_bucket == arr[i])
            {
                res[0] = nonset_bucket;
                res[1] = set_bucket;
                return res;
            }
        }
        res[1] = nonset_bucket;
        res[0] = set_bucket;
        return res;
    }