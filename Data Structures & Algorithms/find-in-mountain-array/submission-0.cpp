/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
   private:
    int findPeak(MountainArray& mountainArr) {
        int n = mountainArr.length();
        int low = 0, high = n - 1;
        int res = -1;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            int left = mountainArr.get(mid - 1);
            int midValue = mountainArr.get(mid);
            int right = mountainArr.get(mid + 1);

            if (left < midValue && midValue < right) {
                low = mid + 1;
            } else if (left > midValue && midValue > right) {
                high = mid - 1;
            } else {
                res = mid;
                break;
            }
        }
        return res;
    }

    int searchLeft(int peak, int target, MountainArray& mountainArr) {
        int low = 0, high = peak - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int val = mountainArr.get(mid);

            if (val == target) {
                return mid;
            } else if (val < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }
    int searchRight(int peak, int target, MountainArray& mountainArr) {
        int low = peak, high = mountainArr.length() - 1;

        while (low <= high) {
            int mid = (low + high) / 2;

            int val = mountainArr.get(mid);

            if (val == target) {
                return mid;
            } else if (val > target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return -1;
    }

   public:
    int findInMountainArray(int target, MountainArray& mountainArr) {
        int peak = findPeak(mountainArr);

        int ansLeft = searchLeft(peak, target, mountainArr);

        int ansRight = searchRight(peak, target, mountainArr);

        if (ansLeft == -1 && ansRight == -1) {
            return -1;
        }
        if (ansLeft == -1) {
            return ansRight;
        }
        return ansLeft;
    }
};