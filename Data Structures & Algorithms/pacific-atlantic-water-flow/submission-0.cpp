class matrix{
public :
int a;
int b;
};
class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>>result;
    
        vector<vector<int>>visited1(heights.size(),vector<int>(heights[0].size(),0));
        vector<vector<int>>visited2(heights.size(),vector<int>(heights[0].size(),0));
        queue<matrix>q;
        queue<matrix>q1;
     

        for(int i=0;i<heights.size();i++)
        {
            for(int j=0;j<heights[0].size();j++)
            {
                if(i==0 || j ==0)
                {
                    
                    q.push({i,j});
                    visited1[i][j]=1;
                }
                if(i==heights.size()-1 || j==heights[0].size()-1)
                {
                   q1.push({i,j});
                   visited2[i][j]=1;
                }
            }
        }
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
                if(drow>=0 && dcol>=0 && drow<heights.size() && dcol<heights[0].size() && heights[drow][dcol]>=heights[t1][t2] && !visited1[drow][dcol])
                {
                    q.push({drow,dcol});
                    visited1[drow][dcol]=1;
                }
            }

        }
        while(!q1.empty())
        {
           
      int t1=q1.front().a;
            int t2=q1.front().b;
            q1.pop();
            int drow1[]={-1,0,1,0};
            int dcol1[]={0,1,0,-1};
            for(int i=0;i<4;i++)
            {
                int drow=t1+drow1[i];
                int dcol=t2+dcol1[i];
                if(drow>=0 && dcol>=0 && drow<heights.size() && dcol<heights[0].size() && heights[drow][dcol]>=heights[t1][t2] && !visited2[drow][dcol])
                {
                    q1.push({drow,dcol});
                    visited2[drow][dcol]=1;
                }
            }
        }
         
    
    for(int i=0;i<heights.size();i++)
    {
        for(int j=0;j<heights[0].size();j++)
        {
          if(visited1[i][j]==1 && visited2[i][j]==1)
          {
            result.push_back({i,j});
          }



        }
    }    
    
  return result;  }
   
};
