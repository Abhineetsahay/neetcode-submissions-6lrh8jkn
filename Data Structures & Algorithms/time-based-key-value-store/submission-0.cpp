class TimeMap {
   public:
    unordered_map<string, vector<pair<int, string>>> timeMap;
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({timestamp, value});
    }

    string get(string keyTofind, int timestamp) {
        auto key = timeMap[keyTofind];
        int low = 0, high = key.size() - 1;

        string result = "";

        while (low <= high) {
            int mid = (low + high) / 2;

            if (key[mid].first <= timestamp) {
                result = key[mid].second;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return result;
    }
};
