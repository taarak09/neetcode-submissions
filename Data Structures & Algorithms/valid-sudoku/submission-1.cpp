class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char,int>mpp;
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                
               if(board[i][j]!='.'){
                if(mpp.find(board[i][j])!=mpp.end())
                {
                    return false;
                }
                mpp[board[i][j]]++;}
                else{
                    continue;
                }
            }
            mpp.clear();
        }

        for(int i=0;i<board[0].size();i++)
        {
            for(int j=0;j<board.size();j++)
            {
                
               if(board[j][i]!='.'){
                if(mpp.find(board[j][i])!=mpp.end())
                {
                    return false;
                }
                mpp[board[j][i]]++;}
                else{
                    continue;
                }
            }
            mpp.clear();
        }
        //donot loose your patience man you can do it pls do this for your good future
        mpp.clear();
        int count=0;
        for(int i=0;i<3;i++)
        {
            for(int i=0;i<3;i++)
            {
                for(int j=0+count;j<3+count;j++)
                {
                    if(board[i][j]!='.'){
                if(mpp.find(board[i][j])!=mpp.end())
                {
                    return false;
                }
                mpp[board[i][j]]++;}
                else{
                    continue;
                }          
                }
            }
            mpp.clear();
            count+=3;

        }
        count=0;
        mpp.clear();
         for(int i=0;i<3;i++)
        {
            for(int i=3;i<6;i++)
            {
                for(int j=0+count;j<3+count;j++)
                {
                    if(board[i][j]!='.'){
                if(mpp.find(board[i][j])!=mpp.end())
                {
                    return false;
                }
                mpp[board[i][j]]++;}
                else{
                    continue;
                }          
                }
            }
            mpp.clear();
            count+=3;

        }
        count=0;
        mpp.clear();
         for(int i=0;i<3;i++)
        {
            for(int i=6;i<9;i++)
            {
                for(int j=0+count;j<3+count;j++)
                {
                    if(board[i][j]!='.'){
                if(mpp.find(board[i][j])!=mpp.end())
                {
                    return false;
                }
                mpp[board[i][j]]++;}
                else{
                    continue;
                }          
                }
            }
            mpp.clear();
            count+=3;

        }

   return true; }
};
