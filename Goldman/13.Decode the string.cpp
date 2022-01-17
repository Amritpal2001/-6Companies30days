string decodedString(string s){
        // code here
        int n = s.size();
        stack<char> st;
        for(int i=0;i<n;i++){
            if(s[i] == ']'){
                string temp="";
                while(!st.empty() && st.top()!='['){
                    temp=st.top()+temp;
                    st.pop();
                }
                st.pop();
                string num="";
                while(!st.empty() && (st.top()>='0' && st.top()<='9')){
                    num=st.top()+num;
                    st.pop();
                }
                int x=stoi(num);
                string rep = "";
                for(int q=0;q<x;q++)
                    rep+=temp;
                for(auto c : rep)
                    st.push(c); 
                
            }
            else
                st.push(s[i]);
            }
            string res="";
            while(!st.empty()){
                res=st.top()+res;
                st.pop();
            }
            return res;
        
    }