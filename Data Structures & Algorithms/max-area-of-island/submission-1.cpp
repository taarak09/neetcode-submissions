class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        //easy peasy question 
        vector<vector<int>>visited(grid.size() , vector<int>(grid[0].size(),0));
        int ans=INT_MIN;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(!visited[i][j] && grid[i][j]==1)
                {
                   ans =max(ans,bfs(grid,visited,i,j));
                }
            }
        }

        if(ans==INT_MIN)
        {
            return 0;
        }
  return ans;  }
    int bfs(vector<vector<int>>& grid,vector<vector<int>>& visited,int i , int j)
    {
        int size=0;
        queue<pair<int,int>>q;
        q.push({i,j});
        visited[i][j]=1;
        size++;
        while(!q.empty())
        {
          int a = q.front().first;
          int b= q.front().second;
          q.pop();
          int drow1[]={-1,0,1,0};
          int dcol1[]={0,1,0,-1};
          for(int i=0;i<4;i++)
          {
           int drow=a+drow1[i];
           int dcol=b+dcol1[i];
           if(drow>=0 && dcol>=0 && drow<grid.size() && dcol<grid[0].size() && !visited[drow][dcol] && grid[drow][dcol]==1)
           {
            q.push({drow,dcol});
            visited[drow][dcol]=1;
            size++;
           }


          }



        }






   return size; }
};
