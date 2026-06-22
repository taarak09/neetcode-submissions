class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        vector<vector<int>>temp;
        for(int i=0;i<matrix.size();i++)
        {
            vector<int>t1;
            for(int j=0;j<matrix[0].size();j++)
            {
               t1.push_back(matrix[j][i]);
            }
            reverse(t1.begin(),t1.end());
            temp.push_back(t1);
        }
        matrix.clear();
        matrix=temp;
        return ;
    }
};
