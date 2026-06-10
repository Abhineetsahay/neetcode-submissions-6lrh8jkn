class Solution {
    bool check(vector<int>& nums, int k, int largest) {
        int arrayCount = 1, sum = 0;

        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            if (sum > largest) {
                sum = nums[i];
                arrayCount++;
            }
        }
        return arrayCount <= k;
    }

   public:
    int splitArray(vector<int>& nums, int k) {
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        int res = high;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (check(nums, k, mid)) {
                res = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return res;
    }
};