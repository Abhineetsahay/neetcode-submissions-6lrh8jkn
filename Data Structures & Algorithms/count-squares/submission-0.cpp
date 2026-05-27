class CountSquares {
   public:
    unordered_map<int, unordered_map<int, int>> ptsCount;
    CountSquares() {}

    void add(vector<int> point) { ptsCount[point[0]][point[1]]++; }

    int count(vector<int> point) {
        int res = 0;
        int px = point[0], py = point[1];

        for (auto& [y, cnt] : ptsCount[px]) {
            int side = y - py;

            if (side == 0) continue;

            int x3 = px + side, x4 = px - side;

            res += cnt * ptsCount[x3][py] * ptsCount[x3][y];
            res += cnt * ptsCount[x4][py] * ptsCount[x4][y];
        }
        return res;
    }
};
