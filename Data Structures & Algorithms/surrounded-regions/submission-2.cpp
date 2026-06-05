class matrix{
public:
int a;
int b;
};
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        vector<vector<int>>visited(board.size(),vector<int>(board[0].size(),-1));
        //bfs se ho hi jayega bilkul
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(visited[i][j]==-1 && board[i][j]=='O' && (i==0 || i==board.size()-1 || j==0 || j==board[0].size()-1))
                {
                    bfs(board,visited,i,j);
                }
            }
        }
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(visited[i][j]==-1 && board[i][j]=='O' )
                {
                    board[i][j]='X';
                }
            }
        }


    }
    void bfs(vector<vector<char>>& board,vector<vector<int>>&visited,int i ,int j)
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
            for(int i=0; i<4;i++)
            {
                int drow=t1+drow1[i];
                int dcol=t2+dcol1[i];
                if(drow>=0 && dcol>=0 && drow<board.size() && dcol<board[0].size() && visited[drow][dcol]==-1 && board[drow][dcol]=='O')
                {
                    q.push({drow,dcol});
                    visited[drow][dcol]=1;
                }
            }
        }

    }
};
