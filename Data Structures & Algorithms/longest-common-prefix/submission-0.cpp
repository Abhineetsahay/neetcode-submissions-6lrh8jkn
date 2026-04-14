class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(),strs.end());
        int n=strs.size();
        string first=strs[0],second=strs[n-1];

        string op;
        int i=0;
        while(i<first.length()){
            if(first[i]==second[i]){
                op+=first[i];
            }
            else{
                break;
            }
            i++;
        }
        return op;
    }
};