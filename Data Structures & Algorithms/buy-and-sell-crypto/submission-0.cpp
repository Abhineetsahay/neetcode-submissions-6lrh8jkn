class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buyStock=prices[0];
        int maxPrice=0;
        for(int i=1;i<n;i++){
            if(prices[i]<buyStock){
                buyStock=prices[i];
            }
            maxPrice=max(maxPrice,prices[i]-buyStock);
        }
        return maxPrice;
    }
};
