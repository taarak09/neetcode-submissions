class Solution {
public:
    bool checkInclusion(string s1, string s2) {
       unordered_map<char,int>mpp;
       for(char e: s1)
       {
        mpp[e]++;
       }
        int right=0;
        int left=0;
        deque<char>dq;
        unordered_map<char,int>mpp1;
        while(right<s2.size())
        {
            dq.push_back(s2[right]);
            mpp1[s2[right]]++;
            if(dq.size()>s1.size())
            {
               
                mpp1[dq.front()]--;
                if(mpp1[dq.front()]<=0)
                {
                    mpp1.erase(dq.front());
                }
                 dq.pop_front();
            }
           if(mpp==mpp1)
           {
            return true;
           }
           






            right++;
        }

   return false; }
};
