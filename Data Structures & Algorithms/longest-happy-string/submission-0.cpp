class Solution {
   public:
    string longestDiverseString(int a, int b, int c) {
        string res = "";
        priority_queue<pair<int, char>> pq;

        if (a != 0) pq.push({a, 'a'});
        if (b != 0) pq.push({b, 'b'});
        if (c != 0) pq.push({c, 'c'});

        while (!pq.empty()) {
            int cnt = pq.top().first;
            char c = pq.top().second;

            pq.pop();

            if (res.size() > 1 && res[res.size() - 1] == c && res[res.size() - 2] == c) {
                if (pq.empty()) break;

                int cnt1 = pq.top().first;
                char c2 = pq.top().second;

                pq.pop();
                res += c2;
                cnt1--;
                if (cnt1 != 0) pq.push({cnt1, c2});
                pq.push({cnt, c});
            } else {
                res += c;
                cnt--;
                if (cnt != 0) pq.push({cnt, c});
            }
        }
        return res;
    }
};