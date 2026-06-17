class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        deque<char>t;
        int ans=INT_MIN;
        for(int i=0;i<s.length();i++)
        {
           
           auto it=find(t.begin(),t.end(),s[i]);
           if(it!=t.end())
           {
            int o=t.size();
            ans=max(ans,o);
            int index=0;
            while(index<t.size() && t[index]!=*it){
             t.pop_front();
             index++;
            }
            t.pop_front();
             t.push_back(s[i]);

           }
           else{
             t.push_back(s[i]);
             int o=t.size();
             ans=max(ans,o);
           }


        }
        if(ans==INT_MIN)
        {
            return 0;
        }
    return ans;}
};
