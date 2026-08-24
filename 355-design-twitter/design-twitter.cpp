class Twitter {
public:

    // tweets of each user
    // {userId, {{time, tweetId}, {time, tweetId}}}
    map<int, vector<pair<int,int>>> tweets;

    // stores who each user follows
    // {followerId, {followeeIds}}
    map<int, set<int>> following;

    int time = 0;

    Twitter() {
        
    }
    
    void postTweet(int userId, int tweetId) {

        tweets[userId].push_back({time, tweetId});

        time++;
    }
    
    vector<int> getNewsFeed(int userId) {

        // max heap
        // {time, tweetId}
        priority_queue<pair<int,int>> pq;

        // 1. Push my tweets
        for(auto tweet : tweets[userId]) {
            pq.push(tweet);
        }

        // 2. Push tweets of people I follow
        for(int person : following[userId]) {

            for(auto tweet : tweets[person]) {
                pq.push(tweet);
            }
        }

        // 3. Get latest 10 tweets
        vector<int> ans;

        while(!pq.empty() && ans.size() < 10) {

            auto top = pq.top();
            pq.pop();

            // top.second = tweetId
            ans.push_back(top.second);
        }

        return ans;
    }
    
    void follow(int followerId, int followeeId) {

        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {

        following[followerId].erase(followeeId);
    }
};
/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */