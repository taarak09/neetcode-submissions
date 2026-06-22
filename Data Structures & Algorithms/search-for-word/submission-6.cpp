class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        //we prefer dfs in word search because in bfs tle and also not good sol
        // in this multiple paths and getting the right path instead of just rejecting paths we explore each path and return the most suceesful or correct path 
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),0));
        // always remember that there must be simgle visited
        // this is a standard pattern man okay yes,
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(!visited[i][j] && board[i][j]==word[0])
                {
                  if(  dfs(board,word,visited,i,j,1))
                  {
                    return true;
                  }
                }
            }
        }

  return false;  }
    bool dfs(vector<vector<char>>& board, string word,vector<vector<int>>&visited,int row,int col,int count)
    {
        if(count==word.length())
        {
            return true;
        }
        int r=row;
        int c=col;
        visited[row][col]=1;
         int drow1[]={0,1,0,-1};
         int dcol1[]={1,0,-1,0};
         for(int i=0;i<4;i++)
         {
            int drow= drow1[i]+r;
            int dcol=dcol1[i]+c;
            if(drow>=0 && dcol>=0 && drow< board.size()&& dcol<board[0].size() && !visited[drow][dcol] && board[drow][dcol]==word[count])
            {
               if( dfs(board,word,visited,drow,dcol,count+1))
               {
                return true;
               }
            } 
         }
        visited[row][col]=0;
   return false; }
};