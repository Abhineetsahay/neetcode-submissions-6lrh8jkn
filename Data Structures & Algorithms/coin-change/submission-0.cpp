class Solution {
private:
    int f(int n,int amount, vector<int>& coins){
        if(amount==0) return 0;
        if(n==0) return 1e9;
        
        int ans=INT_MAX;
        if(coins[n-1]<=amount){
            ans=min(f(n-1,amount,coins),1+f(n,amount-coins[n-1],coins));
        }
        else{
            ans=f(n-1,amount,coins);
        }
        return ans;
    }
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        int ans=f(n,amount,coins);
        return ans==1e9?-1:ans;
    }
};
