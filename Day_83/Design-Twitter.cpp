#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

class Twitter {
public:
    // Stores all tweets from all users in chronological order.
    // pair: {userId, tweetId}
    std::vector<std::pair<int, int>> all_tweets;

    // Stores the set of users each user follows.
    // Using unordered_set for fast lookups (O(1) on average).
    std::unordered_map<int, std::unordered_set<int>> followers;

    Twitter() {
        // Constructor is fine as is.
    }
    
    void postTweet(int userId, int tweetId) {
        // Add the new tweet to our global, chronological list.
        all_tweets.push_back({userId, tweetId});
    }
    
    std::vector<int> getNewsFeed(int userId) {
        std::vector<int> feed;
        int count = 0;

        // Get the set of users that the current user follows.
        std::unordered_set<int>& followed_users = followers[userId];

        // Iterate through all tweets in reverse chronological order (newest first).
        for (auto it = all_tweets.rbegin(); it != all_tweets.rend(); ++it) {
            if (count == 10) {
                break; // Stop when we have 10 tweets.
            }

            int post_author = it->first;
            int tweet_id = it->second;

            // A tweet is relevant if it's from the user OR from someone they follow.
            // The set `followed_users` has a fast `count` method.
            if (post_author == userId || followed_users.count(post_author)) {
                feed.push_back(tweet_id);
                count++;
            }
        }
        return feed;
    }
    
    void follow(int followerId, int followeeId) {
        // Add the followee to the follower's set of followed users.
        followers[followerId].insert(followeeId);
    }
    
    void unfollow(int followerId, int followeeId) {
        // Correctly remove the followee from the follower's set.
        followers[followerId].erase(followeeId);
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