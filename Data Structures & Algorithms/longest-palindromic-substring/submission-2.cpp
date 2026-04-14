class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int startInd=0;
        int len=0;
        vector<vector<bool>> dp;
        dp.assign(n,vector<bool>(n,false));

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(s[i]==s[j] && (j-i<=2 || dp[i+1][j-1])){
                    dp[i][j]=true;
                    if(j-i+1>len){
                        startInd=i;
                        len=j-i+1;
                    }
                }
            }
        }
        return s.substr(startInd,len);
    }
};
