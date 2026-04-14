class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length())return false;
        unordered_map<char, int> charCnt;
        for(char c:s){
            charCnt[c]++;
        }
        for(char c:t){
            if(charCnt.find(c)==charCnt.end()||charCnt[c]==0) return false;
            charCnt[c]--;
        }
        return true;
    }
};
