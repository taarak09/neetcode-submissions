class matrix{
public:
int a ;
int b;
int c;
};
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        // jo hoga woh bfs se hi hoga mere dost 
        //bfs i sthe god my friend 
       
        for(int i=0;i<grid.size();i++)
        {
          for(int j=0;j<grid[0].size();j++)
          {
            if(grid[i][j]==INT_MAX )
            {
               vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
                 grid[i][j]=bfs(grid,visited,i,j);
                 
                 
            }
          }
        }


    }
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i,int j)
    {
      int ans=1e9;
      int INF=INT_MAX;
      queue<matrix>q;
      q.push({i,j,0});
      visited[i][j]=1;
      while(!q.empty())
      {
        int t1=q.front().a;
        int t2=q.front().b;
        int dist=q.front().c;
        if(grid[t1][t2]==0)
        {
            ans=min(ans,dist);
            return ans;
        }
        q.pop();
        int dcol[]={0,1,0,-1};
        int drow[]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
          int drow1=t1+drow[i];
          int dcol1=t2+dcol[i];
          if(drow1>=0 && dcol1>=0 && drow1<grid.size() && dcol1<grid[0].size() && !visited[drow1][dcol1] && grid[drow1][dcol1]!=-1)
          {
                 q.push({drow1,dcol1,dist+1});
                 visited[drow1][dcol1]=1;
          }
        }
      }
    return INF;}
};
