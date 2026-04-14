class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            int t=target-num;
            if(mp.find(t)!=mp.end()) return {min(i,mp[t]),max(i,mp[t])};
            mp[num]=i;
        }
        return {-1,-1};
    }
};
