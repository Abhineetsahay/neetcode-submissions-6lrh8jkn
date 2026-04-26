class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0,count=0;

        unordered_map<int,int>sumFreq;

        for(int i=0;i<n;i++){
            sum+=nums[i];

            if(sum==k){
                count++;
            }

            if(sumFreq.find(abs(k-sum))!=sumFreq.end()){
                count+=sumFreq[abs(k-sum)];
            }
            // else{
                sumFreq[sum]++;
            
        }
        return count;
    }
};