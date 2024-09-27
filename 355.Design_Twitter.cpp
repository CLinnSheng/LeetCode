
class Twitter {
public:
  std::unordered_map<int, std::unordered_set<int>> follows;
  std::unordered_map<int, std::vector<std::pair<int, int>>> tweets;
  int tweet_cnt = 0;

  Twitter() : tweet_cnt{0} {}

  // Use a hashmap for mapping the user to the list of tweet it had tweeted
  void postTweet(int userId, int tweetId) {
    tweets[userId].emplace_back(tweet_cnt++, tweetId);
  }

  // getting the tweets of the 10 most recent tweet.
  // from all user including yourself
  std::vector<int> getNewsFeed(int userId) {
    std::vector<int> recent_tweets;

    auto compare = [](const std::pair<int, int> &a,
                      const std::pair<int, int> &b) {
      return a.first < b.first;
    };

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        decltype(compare)>
        maxHeap(compare);

    // 10 most recent feed include its own post also
    follows[userId].insert(userId);
    for (const auto &followingId : follows[userId]) {
      if (tweets.count(followingId)) {
        for (const auto &_tweet : tweets[followingId])
          maxHeap.emplace(_tweet);
      }
    }

    while (!maxHeap.empty()) {
      auto recent = maxHeap.top();
      maxHeap.pop();
      recent_tweets.emplace_back(recent.second);
      if (recent_tweets.size() == 10)
        break;
    }
    return std::move(recent_tweets);
  }

  // the follower might follow more than 1 id
  // so the data structure that will be use for easy to handler is
  // a hashmap mapping to a set data structure
  // this only take O(1) for finding
  // this will be use for follow and unfollow
  void follow(int followerId, int followeeId) {
    follows[followerId].insert(followeeId);
  }

  void unfollow(int followerId, int followeeId) {
    follows[followerId].erase(followeeId);
  }
};
