class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      //lets do this one man
      //this is a common sliding window problem
      deque<char>dq;
      unordered_map<char,int>mpp;
      int left=0;
      int right=0;
      int ans=0;
      while(right<s.length())
      {
        dq.push_back(s[right]);
        if(mpp.find(s[right])!=mpp.end())
        {
          char temp=dq.back();

          dq.pop_back();
          ans=max(ans,(int)dq.size());
          dq.push_back(temp);
          while(dq.front()!=temp)
          {
            mpp.erase(dq.front());
            dq.pop_front();
          }
          dq.pop_front();
          mpp[temp]++;
          ans=max(ans,(int)dq.size());
        }
        else{
          mpp[s[right]]++;
          ans=max(ans,(int)dq.size());
        }
       






        right++;
      }
   return ans; }
};
