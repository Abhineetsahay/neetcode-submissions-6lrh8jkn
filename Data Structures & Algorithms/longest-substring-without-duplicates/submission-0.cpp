class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len=s.length();
        int left=0,right=0;
        int ans=0;

        unordered_map<char,int> freqChar;
        while(right<len){
            if(freqChar.find(s[right])!=freqChar.end()){
                left=max(left,freqChar[s[right]]+=1);
            }
            freqChar[s[right]]=right;
            ans=max(ans,right-left+1);
            right++;
        }
        return ans;
    }
};
