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
        int low = 0, high = mountainArr.length() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                low = mid + 1;
            else
                high = mid;
        }

        return low;
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