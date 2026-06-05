class Solution {
public:
    bool isAnagram(string s, string t) {
        //optimal approach is to make a frequency array of 26 letters lower case
         unordered_map<char,int>mpp;
         for(char d:s)
         {
            mpp[d]++;
         }
         for(char e :t)
         {
            mpp[e]--;
         }
         for(auto [key,value]:mpp)
         {
            if(value!=0)
            {
                return false;
            }
         }
        
        
        
        return true; }
};
