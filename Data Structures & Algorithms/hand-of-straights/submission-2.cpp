class Solution {
   public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();

        if (n % groupSize != 0) return false;

        map<int, int> cnt;

        for (int i = 0; i < n; i++) {
            cnt[hand[i]]++;
        }

        for (auto& it : cnt) {
            int start = it.first;
            int freq = it.second;

            if (freq > 0) {
                for (int i = 0; i < groupSize; i++) {
                    if (cnt[i + start] < freq) {
                        return false;
                    }
                    cnt[i + start] -= freq;
                }
            }
        }
        return true;
    }
};
