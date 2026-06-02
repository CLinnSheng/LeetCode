#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
/*
 * Each tweet comes with a unique tweetId
 * Things we need to track:
 * 1. The following of the users
 *  - To easily access all the following of a user by its user id is using a hashmap
 *  - And to get the following, we can store all of it under a hash set
 * 2. The tweets from each users
 *  - A hashmap map the user id to a list of tweets it posted
 *  - For the tweet we store it as a pair of time & uniqueId because when we push into the heap, it can sort according
 * to the time
 * 3. We also need an internal counter to track the time where the tweet get created
 * 4. Getting the 10 most recent we can store all the tweets inside a heap and just get 10 out of it
 * */
class Twitter
{
    std::unordered_map<int, std::unordered_set<int>> followingMap;
    std::unordered_map<int, std::vector<std::pair<int, int>>> tweetsMap;
    int time{};

  public:
    Twitter()
    {
    }

    void postTweet(int userId, int tweetId)
    {
        // Insert into the user post tweet list
        tweetsMap[userId].push_back(std::pair{time++, tweetId});
    }

    std::vector<int> getNewsFeed(int userId)
    {
        // Time Complexity: O(nlgn)
        // Space Complexity: O(N*M + N*m + n)
        // N is the total number of users
        // M is the maximum number of tweets by any user
        // m is the total number of following user

        struct Comparator
        {
            bool operator()(const std::pair<int, int> &A, const std::pair<int, int> &B)
            {
                return A.first < B.first;
            };
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, Comparator> maxHeap;

        // Show the user own post as well
        // So we push it self into its own map
        followingMap[userId].insert(userId);

        // Push all the tweets into the heap
        for (const auto following : followingMap[userId])
        {
            for (const auto &tweet : tweetsMap[following])
            {
                maxHeap.push(tweet);
            }
        }

        std::vector<int> tweets;
        while (!maxHeap.empty())
        {
            if (tweets.size() == 10)
            {
                break;
            }

            auto [_, id] = maxHeap.top();
            maxHeap.pop();

            tweets.push_back(id);
        }

        return tweets;
    }

    void follow(int followerId, int followeeId)
    {
        // Add into the following Map
        followingMap[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId)
    {
        // remove it from the map
        followingMap[followerId].erase(followeeId);
    }
};
