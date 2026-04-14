class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.length();

        int left=0,right=0;
        int ans=0;
        unordered_map<char,int>charFreq;
        int maxCharFreq=0;
        while(right<n){
            charFreq[s[right]]++;
            maxCharFreq=max(maxCharFreq,charFreq[s[right]]);

            while((right-left+1)-maxCharFreq>k){
                charFreq[s[left]]--;
                left++;
            }
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
