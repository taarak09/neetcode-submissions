class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        //good question on spiral traversal in am matrix
        vector<int>ans;
        int count=0;
      vector<vector<int>>visited(matrix.size(),vector<int>(matrix[0].size(),0));
        int cmp=0;
        if(matrix.size()%2==0)
        {
            cmp=matrix.size()/2;
        }
        else{
            cmp=(matrix[0].size()/2)+1;
        }
        for(int i=0;i<matrix.size();i++)
        {

            for(int j=0;j<matrix[0].size();j++)
            {
                if(i==j)
                {
                    if(i<cmp ){
                    traversal(matrix,ans,i,j,count,visited);}
                    else{
                        return ans;
                    }
                   
                }
            }
            count++;
        }
      
        
   return ans; }
    vector<int> traversal(vector<vector<int>> & matrix,vector<int>& result,int row,int col,int count,vector<vector<int>> & visited)
    {
        int u=0;
        int startr=row;
        int startc=col;
        int endr=matrix.size()-count-1;
        int endc=matrix[0].size()-count-1;
       for(int i=startc;i<=endc;i++)
       {
        if(!visited[startr][i]){
        result.push_back(matrix[startr][i]);
        visited[startr][i]=1;
        }
       }
      
       for(int i=startr+1;i<=endr;i++)
       {
        if(!visited[i][endc]){
        result.push_back(matrix[i][endc]);
        visited[i][endc]=1;}
       
       }
       
       for(int i=endc-1;i>=startc;i--)
       {
        if(!visited[endr][i]){
        result.push_back(matrix[endr][i]);
        visited[endr][i]=1;}
       
       }
    
       for(int i=endr-1;i>startr;i--)
       {
        if(!visited[i][startc]){
          result.push_back(matrix[i][startc]);
          visited[i][startc]=1;}
       }
    

   return result; }
};
