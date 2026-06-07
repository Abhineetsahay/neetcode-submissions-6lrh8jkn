class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();

        int low = 0, high = n - 1;
        int res = n;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (nums[mid] == target) {
                return mid;
            }
            if (nums[mid] < target) {
                low = mid + 1;
            } else {
                res = mid;
                high = mid - 1;
            }
        }
        return res;
    }
};