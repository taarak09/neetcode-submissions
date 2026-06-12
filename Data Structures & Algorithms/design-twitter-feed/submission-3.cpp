class Twitter {
public:
   unordered_map<int,vector<pair<int,int>>>mpp;
   vector<vector<int>>adj;//graph component;
   int count;
    Twitter() {
        count=0;
        adj.resize(100);
    }
    
    void postTweet(int userId, int tweetId) {
        count++;
        mpp[userId].push_back({count,tweetId});
    }
    
    vector<int> getNewsFeed(int userId) {
        vector<pair<int,int>>dq=mpp[userId];
       for(int i=0;i<adj[userId].size();i++)
       {
          for(pair<int,int>p : mpp[adj[userId][i]])
          {
             dq.push_back(p);
          }
       }
       sort(dq.begin(),dq.end());
       reverse(dq.begin(),dq.end());
       vector<int>result;
       for(int i=0;i<dq.size();i++)
       {
         result.push_back(dq[i].second);
         if(result.size()>10)
         {
            result.pop_back();
            break;
         }
       }

   return result; }
    
    void follow(int followerId, int followeeId) {
        for(int i=0;i<adj[followerId].size();i++)
        {
            if(adj[followerId][i]==followeeId)
            {
                return ;
            }
        }
        if(followerId!=followeeId){
        adj[followerId].push_back(followeeId);
        }
    }
    
    void unfollow(int followerId, int followeeId) {
         if(followerId!=followeeId){
        for(int i=0;i<adj[followerId].size();i++)
        {
            if(adj[followerId][i]==followeeId)
            {
                adj[followerId].erase(adj[followerId].begin()+i);
                break;
            }
        }
         }
    }
};
