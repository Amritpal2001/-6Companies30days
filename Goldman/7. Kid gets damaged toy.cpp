int findPosition(int N , int M , int K) {
        // code here
        if(M%N != 0)
            M=M%N;
        int x = (K+M-1)%N;
        return (x==0) ? N : x;
    }

