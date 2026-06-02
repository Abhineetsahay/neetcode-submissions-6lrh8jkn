class Solution {
   public:
    bool valid(string s, int low, int high) {
        while (low < high) {
            if (s[low] != s[high]) return false;
            low++;
            high--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;

        while (left < right) {
            if (s[left] != s[right]) {
                return valid(s, left + 1, right) || valid(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};