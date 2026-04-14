class Solution {
public:
    int binarySrch(vector<int> num, int target, int n) {
        int l = 0, h = n - 1;
        while (l <= h) {
            int mid = (l + h) / 2;
            if (num[mid] == target) return 1;
            else if(num[mid]<target) l=mid+1;
            else h=mid-1;
        }
        return 0;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int i = 0; i < m; i++) {
            int res = binarySrch(matrix[i], target, n);
            if(res) return true;
        }
        return false;
    }
};