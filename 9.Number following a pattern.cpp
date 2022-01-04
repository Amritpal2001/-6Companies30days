string printMinNumberForPattern(string S){
        // code here 
        string res="";
        stack<int> st;
        for(int i=0;i<=S.size();i++){
            st.push(i+1);
            if(i == S.size() || S[i] == 'I'){
                while(!st.empty()){
                    res+=(st.top()+'0');
                    st.pop();
                }
            }
        }
        return res;
    }

