class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>mpp;
        for(int i=0;i<s.length();i++)
        {
         mpp[s[i]]++;
        }
        unordered_map<char,int>mpp1;
        for(int i=0;i<t.length();i++)
        {
         mpp1[t[i]]++;
        }
        if(mpp==mpp1)
        {
         return true;
        }

    return false;}
};
