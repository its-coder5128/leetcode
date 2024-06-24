class Twitter {
    int postTime;
    unordered_map<int,vector<pair<int,int>>> posts;
    unordered_map<int,unordered_set<int>> following;

public:
    Twitter() {
        postTime = 0;
    }
    
    void postTweet(int userId, int tweetId) {
        posts[userId].push_back({postTime,tweetId});
        postTime++;
    }
    
    vector<int> getNewsFeed(int userId) {
        priority_queue<pair<int,int>> pq;
        for(auto it:posts[userId])
            pq.push(it);
        
        for(auto users:following[userId])
        {
            for(auto it:posts[users])
                pq.push(it);
        }

        vector<int> topPost;

        int n = pq.size();

        for(int i = 0;i<min(n,10);i++)
        {
            pair<int,int> top = pq.top();
            pq.pop();

            topPost.push_back(top.second);
        }

        return topPost;
    }
    
    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        if(following.find(followerId)!=following.end() && following[followerId].count(followeeId))
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