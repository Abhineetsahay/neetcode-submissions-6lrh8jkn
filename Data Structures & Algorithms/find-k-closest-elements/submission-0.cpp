class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
         int n = arr.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>> maxHeap;

        for (int i = 0; i < n; i++) {
            maxHeap.push({abs(x-arr[i]), arr[i]});
        }
        while (maxHeap.size() > k) {
            maxHeap.pop();
        }
        vector<int> ans;

        while (!maxHeap.empty()) {
            ans.push_back(maxHeap.top().second);
            maxHeap.pop();
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};