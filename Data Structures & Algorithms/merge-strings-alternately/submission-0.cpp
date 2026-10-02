class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string temp="";
        int left=0;
        int right=0;
        while(left<word1.size() && right<word2.size())
        {
            temp+=word1[left];
            temp+=word2[right];
            left++;
            right++;
        }
        while(left<word1.size())
        {
            temp+=word1[left];
            left++;
        }
        while(right<word2.size())
        {
            temp+=word2[right];
            right++;
        }
   return temp; }
};