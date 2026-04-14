class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s(nums.begin(), nums.end());
        int maxLen=0;

        for(int num:nums){
            if(s.find(num-1)==s.end()){
                int len=0;
                while(s.find(num+len)!=s.end()){
                    len++;
                }
                maxLen=max(maxLen,len);
            }
        }
        return maxLen;
    }
};
