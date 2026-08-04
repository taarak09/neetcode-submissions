class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        int ans=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]=='1' && !visited[i][j])
                {
                    bfs(grid,visited,i,j);
                    ans+=1;
                }
            }
        }

   return ans; }
    void bfs ( vector<vector<char>>& grid,vector<vector<int>>& visited,int i,int j)
    {
        queue<pair<int,int>>q;

        q.push({i,j});
        visited[i][j]=1;
        while(!q.empty())
        {
           int a=q.front().first;
           int b=q.front().second;
           q.pop();
           int dcol[]={0,1,0,-1};
           int drow[]={-1,0,1,0};
           for(int i=0;i<4;i++)
           {
            int dcol1=b+dcol[i];
            int drow1=a+drow[i];
            if(dcol1>=0 && drow1>=0 && drow1<grid.size() && dcol1<grid[0].size() && !visited[drow1][dcol1] && grid[drow1][dcol1]=='1')
            {
                q.push({drow1,dcol1});
                visited[drow1][dcol1]=1;
            }

           }
        }
    }
};
