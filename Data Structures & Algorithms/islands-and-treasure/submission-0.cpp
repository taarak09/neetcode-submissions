class matrix{
public :
int a;
int b;
int dist;
};
class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int INF=2147483647;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
              if(grid[i][j]==INF)
              {
                bfs(grid,i,j);
              }
            }
        }
    }
    void bfs(vector<vector<int>>& grid,int i1 ,int j1)
    {
         int INF=2147483647;
        
        queue<matrix>q;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        q.push({i1,j1,0});
        visited[i1][j1]=1;
        while(!q.empty())
        {
          int t1=q.front().a;
          int t2=q.front().b;
          int t3=q.front().dist;
          
          q.pop();
          int drow1[]={-1,0,1,0};
          int dcol1[]={0,1,0,-1};
          for(int i=0;i<4;i++)
          {
             int drow= t1+drow1[i];
             int dcol=t2+dcol1[i];
             if(drow>=0 && drow<grid.size() && dcol>=0 && dcol<grid[0].size() && grid[drow][dcol]!=-1 && !visited[drow][dcol])
             {
                q.push({drow,dcol,t3+1});
                visited[drow][dcol]=1;
                if(grid[drow][dcol]==0)
                {
                   
                    grid[i1][j1]=t3+1;
                     return;
                }
             }



          }




        }
        
        
            grid[i1][j1]=INF;
        
    }
};
