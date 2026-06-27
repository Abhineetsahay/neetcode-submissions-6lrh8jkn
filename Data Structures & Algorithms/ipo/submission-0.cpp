class Solution {
   public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int, int>> combine(n);

        for (int i = 0; i < n; i++) {
            combine[i] = {capital[i], profits[i]};
        }
        sort(combine.begin(), combine.end());

        priority_queue<int> pq;

        int i = 0, j = 0;
        while (i < k) {
            while (j < n && combine[j].first <= w) {
                pq.push(combine[j].second);
                j++;
            }
            if (pq.empty()) return w;

            w += pq.top();
            pq.pop();
            i++;
        }
        return w;
    }
};