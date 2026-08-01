class matrix{
public:
int a ;
int b;

};


class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        queue<matrix>q;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),0));
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
               if(grid[i][j]==1 && !visited[i][j] )
               {
                  bfs(i,j,grid,visited);

               }
            }
        }
        // now i have a connected land grpah and main challenge is how to find the perimeter my friend
       return perimeter(visited);

    }
    void bfs(int i,int j,vector<vector<int>>& grid, vector<vector<int>>& visited)
    {
        visited[i][j]=1;
        queue<matrix>q;
        q.push({i,j});
        while(!q.empty())
        {
            int i=q.front().a;
            int j=q.front().b;
            q.pop();
            int drow[]={-1,0,1,0};
            int dcol[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int drow1=i+drow[i];
                int dcol1=j+dcol[i];
                if(drow1>=0 && dcol1>=0 && drow1<grid.size() && dcol1<grid[0].size() && !visited[drow1][dcol1] && grid[drow1][dcol1]==1)
                {
                    q.push({drow1,dcol1});
                    visited[drow1][dcol1]=1;
                }
            }
        }
    }
    int perimeter ( vector<vector<int>>& visited)
    {
        int ans=0;
        for(int i=0;i<visited.size();i++)
        {
            for(int j=0;j<visited[0].size();j++)
            {
                if(visited[i][j]==1)
                {
                    ans+=peri(visited,i,j);
                }
            }

        }
        return ans;
    }
    int peri(vector<vector<int>>& visited,int i1,int j1)
    {
        int count=0;
        int dcol1[]={0,1,0,-1};
        int drow1[]={-1,0,1,0};
        for(int i=0;i<4;i++)
        {
            int drow=i1+drow1[i];
            int dcol=j1+dcol1[i];
            if(drow>=0 && dcol>=0 && drow<visited.size() && dcol<visited[0].size() && visited[drow][dcol]==1)
            {
                 count++;
            }


        }
        return 4-count;
    }
};