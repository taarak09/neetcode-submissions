class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        vector<int>visited(10,0);
      
        vector<int>visited1(10,0);
        
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
              if( board[i][j]!='.' && !visited[board[i][j]-'0'] )
              {
                int num=board[i][j]-'0';
                visited[num]=1;
              }
              else if(board[i][j]!='.' && visited[board[i][j]-'0']==1 ){
                return false;
              }
              if( board[j][i]!='.' && !visited1[board[j][i]-'0'] )
              {
                int num2=board[j][i]-'0';
                visited1[num2]=1;
              }
              else if (board[j][i]!='.' && visited1[board[j][i]-'0']==1){
                return false;
              }
              


            }
            
            fill(visited.begin(),visited.end(),0);
           
            fill(visited1.begin(),visited1.end(),0);
            //fill function is used remember this man ,pls remember this
            
        }
        int count=0;
             int counter=0;
        for(int i1=0;i1<9;i1++){
             fill(visited.begin(),visited.end(),0);
             if(i1!=0 && i1%3==0)
             {
                counter+=3;
                count=0;
             }
             
        for(int i=0+counter;i<3+counter;i++)
        {
            for(int j=0+count;j<3+count;j++)
            {
                 if( board[i][j]!='.' && !visited[board[i][j]-'0'] )
              {
                int num=board[i][j]-'0';
                visited[num]=1;
              }
              else if(board[i][j]!='.' && visited[board[i][j]-'0']==1 ){
                return false;
              }
            }

            
        }
        count+=3;
        }
        
      
    return true;}
};
