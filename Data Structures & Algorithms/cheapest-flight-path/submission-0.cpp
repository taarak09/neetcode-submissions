class matrix{
public :
int a;
int costs;
int stops;
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(int i=0;i<flights.size();i++)
        {
            for(int j=0;j<3;j++)
            {
                if(j==0)
                {
                    adj[flights[i][j]].push_back({flights[i][j+1],flights[i][j+2]});
                }
            }
        }
        //throough bfs finding the shortest path
        queue<matrix>q;
        q.push({src,0,0});
        vector<int>dist(n,1e9);
        dist[src]=0;
        int ans=1e9;
        while(!q.empty())
        {
           int t1=q.front().a;
           int t2=q.front().costs;
           int t3=q.front().stops;
           q.pop();
           if(t3-1 >k)
           {
            continue;
           }
           if(t1==dst)
           {
              ans=min(ans,t2);
              continue;
              //to prevent time limit exceed and infinte loop
           }
           for(pair<int,int> next : adj[t1])
           {
              if(t2+next.second<dist[next.first])
              {
                //it prevents memory limit exceed by storing only minimum path in queue
                dist[next.first]=t2+next.second;
                q.push({next.first,t2+next.second,t3+1});
              }
           }
        }
        if(ans==1e9)
        {
            return -1;
        }
        return ans;
    }
};
