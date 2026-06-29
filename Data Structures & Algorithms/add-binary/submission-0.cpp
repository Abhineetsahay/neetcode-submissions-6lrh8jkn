class Solution {
   public:
    string addBinary(string a, string b) {
        string ans = "";

        int i = a.size() - 1;
        int j = b.size() - 1;
        int carry = 0;

        while (i >= 0 || j >= 0 || carry != 0) {
            int digA = i >= 0 ? a[i] - '0' : 0;
            int digB = j >= 0 ? b[j] - '0' : 0;

            int sum = digA + digB + carry;

            ans += (sum % 2) + '0';
            carry = sum / 2;
            i--;
            j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};