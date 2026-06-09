class Solution {
   private:
    bool check(vector<int>& weights, int days, int capacity) {
        int currCapacity = 0;
        int day = 1;
        for (int i = 0; i < weights.size(); i++) {
            if (currCapacity + weights[i] > capacity) {
                day++;
                currCapacity = 0;
            }
            currCapacity += weights[i];
        }
        return day <= days;
    }

   public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int low = *max_element(weights.begin(), weights.end());
        int high = accumulate(weights.begin(), weights.end(), 0);
        int ans = high;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (check(weights, days, mid)) {
                ans = min(ans, mid);
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return ans;
    }
};