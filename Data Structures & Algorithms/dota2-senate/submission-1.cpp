class Solution {
   public:
    string predictPartyVictory(string senate) {
        int n = senate.size();
        queue<int> r, d;

        for (int i = 0; i < n; i++) {
            if (senate[i] == 'R') {
                r.push(i);
            } else {
                d.push(i);
            }
        }

        while (!r.empty() && !d.empty()) {
            int rInd = r.front();
            r.pop();

            int dInd = d.front();
            d.pop();

            if (rInd < dInd) {
                r.push(rInd + n);
            } else {
                d.push(dInd + n);
            }
        }
        return r.empty() ? "Dire" : "Radiant";
    }
};