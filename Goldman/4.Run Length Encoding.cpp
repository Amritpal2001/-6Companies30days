string encode(string src)
{     
  //Your code here 
  string res="";
  char ch = src[0];
    int i=0;
    int n =src.size();
    int cnt = 0;
    while(i<n){
        while(src[i] == ch && i<n){
            i++;
            cnt++;
        }
        res+=ch + to_string(cnt);
        cnt = 0;
        ch = src[i];
    }
    return res;
} 