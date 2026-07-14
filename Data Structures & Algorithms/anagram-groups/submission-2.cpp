class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // recall the logic my boy i know you can do this i know you can do this without seeing the solution
        vector<string>temp=strs;
        vector<vector<string>>result;
        unordered_map<string,pair<int,vector<string>>>mpp1;
        for(int i=0;i<temp.size();i++)
        {
            string f=temp[i];
            sort(f.begin(),f.end());
            mpp1[f].first++;
            mpp1[f].second.push_back(temp[i]);
        }
        for(auto const & [key,value]:mpp1)
        {
            result.push_back(value.second);
        }

    return result;}
};