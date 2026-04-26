class Solution {
public:

    string encode(vector<string>& strs) {
        string s="";
        for(auto str:strs){
            s+=str+" ";
        }
        return s;
    }

    vector<string> decode(string s) {
        vector<string> sd;
        string st="";
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                sd.push_back(st);
                st="";
                continue;
            }
            st+=s[i];
        }
        return sd;
    }
};
