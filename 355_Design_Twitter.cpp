/*
Design a simplified version of Twitter where users can post tweets, follow/unfollow another user and is able to see the 10 most recent tweets in the user's news feed. Your design should support the following methods:

postTweet(userId, tweetId): Compose a new tweet.
getNewsFeed(userId): Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent.
follow(followerId, followeeId): Follower follows a followee.
unfollow(followerId, followeeId): Follower unfollows a followee.
Example:

Twitter twitter = new Twitter();

// User 1 posts a new tweet (id = 5).
twitter.postTweet(1, 5);

// User 1's news feed should return a list with 1 tweet id -> [5].
twitter.getNewsFeed(1);

// User 1 follows user 2.
twitter.follow(1, 2);

// User 2 posts a new tweet (id = 6).
twitter.postTweet(2, 6);

// User 1's news feed should return a list with 2 tweet ids -> [6, 5].
// Tweet id 6 should precede tweet id 5 because it is posted after tweet id 5.
twitter.getNewsFeed(1);

// User 1 unfollows user 2.
twitter.unfollow(1, 2);

// User 1's news feed should return a list with 1 tweet id -> [5],
// since user 1 is no longer following user 2.
twitter.getNewsFeed(1);
*/
#include <unordered_map>
#include <vector>
#include <queue>
#include <set>
using namespace std;

struct Tweet {
	int time_stamp_;
	int tweetId_;
	Tweet* next_;
	Tweet(){
		tweetId_ = 0;
		time_stamp_ = 0;
		next_ = NULL;
	}
	Tweet(int tweetId, int time_stamp){
		tweetId_ = tweetId;
		time_stamp_ = time_stamp;
		next_ = NULL;
	}
};

struct EarlierThan
{
  bool operator()(const Tweet& lhs, const Tweet& rhs) const
  {
	  return lhs.time_stamp_ < rhs.time_stamp_;
  }
};

struct User {
	set<int> followees_;
	Tweet* head_;
	User(){
		head_ = NULL;
	};
	User& operator = (const User& t){
		head_ = t.head_;
		followees_ = t.followees_;
		return *this;
	}
};

class Twitter {
private:
	unordered_map<int, User> users_;
	int time_stamp_;
public:
    /** Initialize your data structure here. */
    Twitter() {
		time_stamp_ = 0;
    }

    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
		Tweet* temp = new Tweet(tweetId, ++time_stamp_);
		temp->next_ = users_[userId].head_;
		users_[userId].head_ = temp;
    }

    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
		if(users_.end()==users_.find(userId)) return vector<int>();
		vector<int> res;
		std::priority_queue<Tweet, vector<Tweet>, EarlierThan> lattest_tweets;
		// fill in lattest_tweets
		if(users_[userId].head_){
			lattest_tweets.push( *users_[userId].head_ );
		}
		for(set<int>::iterator followee_iter = users_[userId].followees_.begin(); \
			   followee_iter != users_[userId].followees_.end(); ++followee_iter){
			if(users_[*followee_iter].head_){
				lattest_tweets.push( *users_[*followee_iter].head_ );
			}
		}	
		// propagate through lattest_tweets
		while( (res.size()<10) && (!lattest_tweets.empty()) ){
			// get the lattest tweet
			Tweet new_twt = lattest_tweets.top();
			lattest_tweets.pop();
			res.push_back( new_twt.tweetId_ );
			// insert the next tweet into queue
			if(new_twt.next_){
				lattest_tweets.push( *new_twt.next_ );
			}
		}
		// return res
		return res;
    }

    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
		if(followerId==followeeId) return;
		users_[followerId].followees_.insert(followeeId);
    }

    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
		unordered_map<int, User>::iterator user_iter = users_.find(followerId);
		if(users_.end()!=user_iter){
			set<int>::iterator followee_iter = user_iter->second.followees_.find(followeeId);
			if(user_iter->second.followees_.end()!=followee_iter){
				user_iter->second.followees_.erase(followee_iter);
			}
		}
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter obj = new Twitter();
 * obj.postTweet(userId,tweetId);
 * vector<int> param_2 = obj.getNewsFeed(userId);
 * obj.follow(followerId,followeeId);
 * obj.unfollow(followerId,followeeId);
 */
