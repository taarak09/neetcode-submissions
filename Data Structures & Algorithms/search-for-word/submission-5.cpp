class matrix{
public:
int a;
int b;
int c;
vector<vector<int>>visited;
};
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
      
  
        bool ans;
     
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                 if(board[i][j]==word[0] )
                 {
                      vector<vector<int>> visited(board.size(),vector<int>(board[0].size(),0));
                   ans=  bfs(board,visited,i,j,word);
                   if(ans)
                   {
                    return true;
                   }
                 }

                
            }
        }
        
 return ans;   }
    bool bfs(vector<vector<char>>& board,vector<vector<int>>& visited,int i,int j,string word)
    {
        int u=word.length();
        int count=1;
        
        queue<matrix>q;
        q.push({i,j,count,visited});
       
        while(!q.empty())
        {
            int e=q.front().a;
            int f=q.front().b;
            int g=q.front().c;
            vector<vector<int>>visi=q.front().visited;
            visi[e][f]=1;
            if(g==word.length())
            {
                return true;
            }
            q.pop();
            int drow1[]={0,1,0,-1};
            int dcol1[]={1,0,-1,0};
            
            for(int i=0;i<4;i++)
            {
                int drow=drow1[i]+e;
                int dcol=dcol1[i]+f;
                if(drow>=0 && dcol>=0 && drow<board.size()&& dcol<board[0].size() && !visi[drow][dcol] && u>count   &&word[g]==board[drow][dcol]) 
                {
                   q.push({drow,dcol,g+1,visi});
                  
                  
                }

            }
        }
      

    return false;}
};
