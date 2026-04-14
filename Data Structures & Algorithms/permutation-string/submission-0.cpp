class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        if(n>m) return false;

        vector<int>freq_s1(26,0),freq_s2(26,0);

        for(int i=0;i<n;i++){
            freq_s1[s1[i]-'a']++;
            freq_s2[s2[i]-'a']++;
        }

        if(freq_s1==freq_s2) return true;

        int left=0,right=n;
        while(right<m){
            freq_s2[s2[left]-'a']--;
            freq_s2[s2[right]-'a']++;
            
            if(freq_s1==freq_s2) return true;

            left++,right++;
        }
        return false;

    }
};
