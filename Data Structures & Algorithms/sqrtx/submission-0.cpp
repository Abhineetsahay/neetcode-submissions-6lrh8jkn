class Solution {
   public:
    int mySqrt(int x) {
        int low = 1, high = x;
        int res = 0;
        while (low <= high) {
            long long m = low + (high - low) / 2;

            if (m * m == x) {
                return m;
            } else if (m * m < x) {
                low = m + 1;
                res = m;
            } else {
                high = m - 1;
            }
        }
        return res;
    }
};