class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>>ans;

        unordered_map<string,vector<string>>strFreq;

        for(int i=0;i<n;i++){
            string t=strs[i];
            
            sort(t.begin(),t.end());

            strFreq[t].push_back(strs[i]);
        }
        for(auto it:strFreq){
           ans.push_back(it.second);
        }
        return ans;
    }
};
