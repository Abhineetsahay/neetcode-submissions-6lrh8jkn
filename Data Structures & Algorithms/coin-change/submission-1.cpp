class Solution {
private:
    vector<vector<int>>dp;
    int f(int n,int amount, vector<int>& coins){
        if(amount==0) return 0;
        if(n==0) return 1e9;
        
        if(dp[n][amount]!=-1) return dp[n][amount];
        int ans=INT_MAX;
        if(coins[n-1]<=amount){
            ans=min(f(n-1,amount,coins),1+f(n,amount-coins[n-1],coins));
        }
        else{
            ans=f(n-1,amount,coins);
        }
        return dp[n][amount]=ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        dp.assign(n+1,vector<int>(amount+1,-1));
        int ans=f(n,amount,coins);
        return ans==1e9?-1:ans;
    }
};
