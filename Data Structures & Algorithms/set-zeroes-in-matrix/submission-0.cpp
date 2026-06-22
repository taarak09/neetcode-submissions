class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<vector<int>>visited(matrix.size(),vector<int>(matrix[0].size(),0));
        vector<pair<int,int>>temp;
        for(int i=0;i<matrix.size();i++)
        {
            for(int j=0;j<matrix[0].size();j++)
            {
                if(matrix[i][j]==0)
                {
                    visited[i][j]=1;
                    temp.push_back({i,j});
                }
            }
        }
        for(int i=0;i<temp.size();i++)
        {
            answer(temp[i].first,temp[i].second,matrix,visited);
        }

    return;}
    void answer(int i,int j,vector<vector<int>>& matrix,vector<vector<int>>& visited)
    {
       for(int  k=0;k<matrix.size();k++)
       {
        if(!visited[k][j]){
            matrix[k][j]=0;
            visited[k][j]=1;}
            else{
                continue;
            }
       }
          for(int h=0;h<matrix[i].size();h++)
          {
            if(!visited[i][h])
            {
                matrix[i][h]=0;
                visited[i][h]=1;
            }
            else{
                continue;
            }
          }



    }
};
