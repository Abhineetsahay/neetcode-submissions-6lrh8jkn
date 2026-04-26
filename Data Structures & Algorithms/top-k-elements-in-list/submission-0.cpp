class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>res;
        unordered_map<int,int>map;
        for(auto num:nums){
            map[num]++;
            // if(map[num]>=k&&find(res.begin(),res.end(),num)==res.end()) res.push_back(num);
        }
        for(auto it:map){
            if(it.second>=k&&find(res.begin(),res.end(),it.first)==res.end()){
                res.push_back(it.first);
            }
        }
        return res;
    }
};
