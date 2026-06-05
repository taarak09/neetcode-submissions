class matrix{
public:
int a ;
int b;
};
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n =grid.size();
        int m = grid[0].size();
        //bfs se hi hojayega
        vector<vector<int>>visited(n,vector<int>(m,-1));
        int num=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==-1 && grid[i][j]=='1')
                {
                    bfs(grid,i,j,visited);
                    num++;
                }
            }
        }

   return num; }
    void bfs(vector<vector<char>>& grid,int i,int j,vector<vector<int>>&visited)
    {
       queue<matrix>q;
       q.push({i,j});
       visited[i][j]=1;
       while(!q.empty())
       {
         int t1=q.front().a;
         int t2=q.front().b;
         q.pop();
         int drow1[]={-1,0,1,0};
         int dcol1[]={0,1,0,-1};
         for(int i=0;i<4;i++)
         {
           int drow=t1+drow1[i];
           int dcol=t2+dcol1[i];
           if(drow>=0 && dcol>=0 && drow<grid.size()&& dcol<grid[0].size() && visited[drow][dcol]==-1 && grid[drow][dcol]=='1')
           {
            q.push({drow,dcol});
            visited[drow][dcol]=1;
           }



         }







       }
    }
};
