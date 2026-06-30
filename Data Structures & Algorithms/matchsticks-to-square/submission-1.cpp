class Solution {
   private:
    bool f(int i, vector<int>& matchsticks, vector<int>& sides, int target) {
        if (i == matchsticks.size()) {
            return sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3];
        }
        for (int j = 0; j < 4; j++) {
            if (sides[j] + matchsticks[i] > target) continue;
            sides[j] += matchsticks[i];
            if (f(i + 1, matchsticks, sides, target)) return true;

            sides[j] -= matchsticks[i];
        }
        return false;
    }

   public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = accumulate(matchsticks.begin(), matchsticks.end(), 0);

        if (sum % 4 != 0) return false;

        vector<int> sides(4, 0);
        int target = sum / 4;
        return f(0, matchsticks, sides, target);
    }
};