class Solution {
private:
    vector<vector<int>> dp;
    bool isPalindrome(const string &s, int i, int j) {
        if(dp[i][j]!=-1) return dp[i][j];
        while (i < j) {
            if (s[i] != s[j]) return dp[i][j]=false;
            i++; j--;
        }
        return dp[i][j]=true;
    }
    void f(int i,int j,int& startInd,int& len,string& s){
        if(i>j) return ;

         if (isPalindrome(s, i, j)) {
            if (len < j - i + 1) {
                len = j - i + 1;
                startInd = i;
            }
        }

        f(i + 1, j, startInd, len, s); 
        f(i, j - 1, startInd, len, s); 
    }
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int startInd=0;
        int len=0;
        dp.assign(n,vector<int>(n,-1));
        f(0,n-1,startInd,len,s);
        return s.substr(startInd,len);
    }
};
