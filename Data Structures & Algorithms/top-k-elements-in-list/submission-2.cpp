class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //for duplicates we use multiset
        multiset<pair<int,int>>ms;
        unordered_map<int,int>mpp;
        for(int i=0;i<nums.size();i++)
        {
            mpp[nums[i]]++;
        }
        for(auto [key,value]:mpp)
        {
            ms.insert({value,key});
        }
        vector<int>final;
        for(pair<int,int> h: ms)
        {
            final.push_back(h.second);
        }
        reverse(final.begin(),final.end());
        vector<int>result;
        for(int i=0;i<k;i++)
        {
            result.push_back(final[i]);
        }
   return result; }
};
