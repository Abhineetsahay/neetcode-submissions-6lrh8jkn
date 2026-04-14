class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>prefixProduct(n);
        vector<int>suffixProduct(n);

        int prefix=1;
        
        for(int i=0;i<n;i++){
            prefixProduct[i]=prefix;
            prefix*=nums[i];
        }
        
        int suffix=1;
        for(int i=n-1;i>=0;i--){
            suffixProduct[i]=suffix;
            suffix*=nums[i];
        }

        vector<int>ans(n);

        for(int i=0;i<n;i++){
            ans[i]=prefixProduct[i]*suffixProduct[i];
        }
        return ans;

    }
};
