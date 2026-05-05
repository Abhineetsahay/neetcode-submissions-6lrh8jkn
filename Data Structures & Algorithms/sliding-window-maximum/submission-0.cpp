class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();

        priority_queue<pair<int, int>> pq;

        for (int i = 0; i < k; i++) {
            pq.push({nums[i], i});
        }
        int left = 0, right = k;

        vector<int> ans;

        ans.push_back(pq.top().first);

        while (right < n) {
            left++;
            pq.push({nums[right], right});
            while (!pq.empty()) {
                if (pq.top().second < left) {
                    pq.pop();
                } else {
                    break;
                }
            }

            ans.push_back(pq.top().first);
            right++;
        }
        return ans;
    }
};
