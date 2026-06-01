class Solution {
   public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int ele1 = 0, cnt1 = 0;
        int ele2 = 0, cnt2 = 0;

        for (int num : nums) {
            if (num == ele1) {
                cnt1++;
            } else if (num == ele2) {
                cnt2++;
            } else if (cnt1 == 0) {
                ele1 = num;
                cnt1++;
            } else if (cnt2 == 0) {
                ele2 = num;
                cnt2++;
            } else {
                cnt1--;
                cnt2--;
            }
        }
        cnt1 = 0, cnt2 = 0;

        for (int num : nums) {
            if (num == ele1)
                cnt1++;
            else if (num == ele2)
                cnt2++;
        }

        vector<int> res;

        if (cnt1 > n / 3) res.push_back(ele1);
        if (cnt2 > n / 3 && ele1 != ele2) res.push_back(ele2);

        if (res.size() == 2 && res[0] > res[1]) {
            swap(res[0], res[1]);
        }
        return res;
    }
};