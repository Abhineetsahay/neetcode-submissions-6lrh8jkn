class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";

        for(int i=0;i<strs.size();i++){
            encoded += to_string(strs[i].size()) + "#" + strs[i];
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        
        while (i < s.size()) {
            int j = i;
            
            while (s[j] != '#') {
                j++;
            }
            int len = stoi(s.substr(i, j - i));
            string str = s.substr(j + 1, len);
            res.push_back(str);
            i = j + 1 + len;
        }
        
        return res;
    }
};
