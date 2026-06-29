class Solution {
   public:
    bool isDivisor(int l, const string& str1, const string& str2) {
        int len1 = str1.size();
        int len2 = str2.size();

        if (len1 % l != 0 || len2 % l != 0) return false;

        int f1 = len1 / l;
        int f2 = len2 / l;

        string pattern = str1.substr(0, l);

        string s1 = "", s2 = "";
        for (int i = 0; i < f1; i++) s1 += pattern;
        for (int i = 0; i < f2; i++) s2 += pattern;

        return s1 == str1 && s2 == str2;
    }

    string gcdOfStrings(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();

        for (int l = min(len1, len2); l >= 1; l--) {
            if (isDivisor(l, str1, str2)) return str1.substr(0, l);
        }

        return "";
    }
};