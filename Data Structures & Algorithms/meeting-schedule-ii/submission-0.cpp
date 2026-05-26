/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
   public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(),
             [](auto& a, auto& b) { return a.start < b.start; });
        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto& interval : intervals) {
            if (!pq.empty() && pq.top() <= interval.start) {
                pq.pop();
            }
            pq.push(interval.end);
        }
        return pq.size();
    }
};
