class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<string>arr;
        arr=strs;
        for(int i=0;i<strs.size();i++)
        {
            sort(arr[i].begin(),arr[i].end());
        }
        unordered_map<string,vector<int>>mpp;
        for(int i=0;i<strs.size();i++)
        {
            mpp[arr[i]].push_back(i);
        }
        vector<vector<string>>result;
        for(auto [key,value]:mpp)
        {
            vector<string>temp;
            for(int r:mpp[key])
            {
                temp.push_back(strs[r]);
            }
            result.push_back(temp);
            temp.clear();
        }

  return result;  }
};
