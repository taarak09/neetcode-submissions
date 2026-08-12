class Solution {
   // bool operator> (const taarak& other)const{
     //   a>other.a
  //  }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        //for djikstra algorithm we need the addjacency list my friend 
        vector<vector<pair<int,int>>>adj(n+1);
        for(int i=0;i<times.size();i++)
        {
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        vector<int>dist(n+1,1e9);
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty())
        {
            int y=pq.top().first;
            int z=pq.top().second;
            pq.pop();
          //isliye mujhe visited ki jarurat nahi padti beta taarak
            for(int i=0;i<adj[z].size();i++)
            {
                // this relaxation condition is the most important condition
                if(y+adj[z][i].second<dist[adj[z][i].first]){
                pq.push({y+adj[z][i].second,adj[z][i].first});
                dist[adj[z][i].first]=y+adj[z][i].second;
                }
            }
        }
        int ans=0;
        for(int i=1;i<dist.size();i++)
        {
            if(dist[i]==1e9)
            {
                return -1;
            }
           ans=max(ans,dist[i]);
        }

   return ans; }
};
