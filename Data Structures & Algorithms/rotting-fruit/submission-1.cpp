class matrix{
public:
int a;
int b;
int c;
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // agood question my friend you can  do this 
        // a ggod level of algorithm 
        //bfs se hi hoga jo bhi hoga woh 
        // both will work simulataneously my friend 
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        queue<matrix>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!visited[i][j] && grid[i][j]==2)
                {
                     q.push({i,j,0});
                     visited[i][j]=1;
                }
            }
        }
     int ans=  bfs(grid,visited,q);
       for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
   return ans; }
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& visited,queue<matrix>&q)
    {
       int ans=0;
        while(!q.empty())
        {
            int t1=q.front().a;
            int t2=q.front().b;
            int t3=q.front().c;
            q.pop();
            ans=max(ans,t3);
            int drow1[]={-1,0,1,0};
            int dcol1[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int drow=t1+drow1[i];
                int dcol=t2+dcol1[i];
                if(drow>=0 && dcol>=0 && drow<grid.size() && dcol<grid[0].size()&& !visited[drow][dcol] && grid[drow][dcol]==1)
                {
                    q.push({drow,dcol,t3+1});
                    visited[drow][dcol]=1;
                }
            }
       }

  return ans;   }
};
