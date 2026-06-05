class matrix{
public:
int a;
int b;
int time;
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        // bfs would be  better 
        int time=0;
        vector<vector<int>>visited(grid.size(),vector<int>(grid[0].size(),-1));
        queue<matrix>q;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j]==2 && visited[i][j]==-1)
                {
                   q.push({i,j,0});
                }
            }
        }
         time= bfs(grid,q,visited);
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(visited[i][j]==-1 && grid[i][j]==1)
                {
                    return -1;
                }
            }
        }
    return time;}
    int bfs(vector<vector<int>>&grid,queue<matrix>&q,vector<vector<int>>&visited)
    {
        int time=0;
        
        
        while(!q.empty())
        {
            int temp=q.front().a;
            int temp1=q.front().b;
            time=q.front().time;
            visited[temp][temp1]=1;
            q.pop();
            int dcol1[4]={0,1,0,-1};
            int drow1[4]={-1,0,1,0};
            for(int i=0;i<4;i++)
            {
                int drow=temp+drow1[i];
                int dcol=temp1+dcol1[i];
                if(  drow>=0 && dcol>=0 && drow<grid.size() && dcol<grid[0].size()  && visited[drow][dcol]==-1 && grid[drow][dcol]==1)
                {
                    q.push({drow,dcol,time+1});
                    visited[drow][dcol]=1;
                }
            }
           
        }
    return time;}
};