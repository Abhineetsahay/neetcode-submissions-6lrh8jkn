class Twitter {
public:
    int time;
    unordered_map<int, priority_queue<pair<int,int>>> tweetMap;
    unordered_map<int, unordered_set<int>> followMap;

    Twitter() {
        time = 0;
    }

    void postTweet(int userId, int tweetId) {
        tweetMap[userId].push({time++, tweetId});
    }

    vector<int> getNewsFeed(int userId) {
        vector<int> ans;

        priority_queue<pair<int,int>> pq;

        followMap[userId].insert(userId);

        for (int user : followMap[userId]) {
            auto temp = tweetMap[user]; 

            while (!temp.empty()) {
                pq.push(temp.top());
                temp.pop();
            }
        }

        while (!pq.empty() && ans.size() < 10) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }

    void follow(int followerId, int followeeId) {
        followMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if (followeeId != followerId) {
            followMap[followerId].erase(followeeId);
        }
    }
};