int CountWays(string str){
		    // Code here
		    int n = str.size();
		    if(str[0] == '0')
		        return 0;
		       
		  int dp[n+1]={0};
		  dp[0] = 1;
		  dp[1] = 1;
		  
		  for(int i=2;i<=n;i++){
		    if(str[i-1]>'0')
		        dp[i]=(dp[i]+dp[i-1])%1000000007;
		    if(str[i-2] == '1' || (str[i-2] == '2' && str[i-1]<='6'))
		       dp[i]=(dp[i]+dp[i-2])%1000000007;
		  }
		    return dp[n];
		}