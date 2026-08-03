class Twitter {
public:
unordered_map<int ,vector<pair<int,int>>>mpp;
vector<vector<int>>adj;
int count;
    Twitter() {
        adj.resize(100);
        count=0;
    }
    
    void postTweet(int userId, int tweetId) {
        count++;
        mpp[userId].push_back({count,tweetId});
        
    }
    
    vector<int> getNewsFeed(int userId) {
       vector<pair<int,int>>arr=mpp[userId];
       for(int i=0;i<adj[userId].size();i++)
       {
           for(pair<int,int> p:mpp[adj[userId][i]])
           {
             arr.push_back(p);
           }
       }
       sort(arr.begin(),arr.end());
       reverse(arr.begin(),arr.end());
       vector<int>result;
       for(int i=0;i<arr.size();i++)
       {
        result.push_back(arr[i].second);
        if(result.size()==10)
        {
            return result;
        }
       }


        
    return result;}
    
    void follow(int followerId, int followeeId) {
        for(int i=0;i<adj[followerId].size();i++)
        {
            if(adj[followerId][i]==followeeId)
            {
                return ;
            }
        }
        if(followerId!=followeeId)
        {
          adj[followerId].push_back(followeeId);

        }
    }
    
    void unfollow(int followerId, int followeeId) {
        for(int i=0;i<adj[followerId].size();i++)
        {
            if(adj[followerId][i]==followeeId)
            {
                adj[followerId].erase(adj[followerId].begin()+i);
                break;
            }
        }
        
    }
};
