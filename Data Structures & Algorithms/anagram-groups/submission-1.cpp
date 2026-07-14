class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>result;
        vector<vector<string>>final;
        vector<int>visited(strs.size(),0);
        for(int i=0;i<strs.size();i++)
        {
            if(visited[i]==1)
            {
                continue;
            }
             visited[i]=1;
            result.push_back(strs[i]);
            unordered_map<char,int>mpp;
            for(char t : strs[i])
            {
                mpp[t]++;
            }
            for(int j=i+1;j<strs.size();j++)
            {
            unordered_map<char,int>mpp1;
            for(char t : strs[j])
            {
                mpp1[t]++;
            }
            if(mpp==mpp1)
            {
                result.push_back(strs[j]);
                 visited[j]=1;
            }
           
            }
           
          final.push_back(result);
          result.clear();
        }

   return final; }
};
