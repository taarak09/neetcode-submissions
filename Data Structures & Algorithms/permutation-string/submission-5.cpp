class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //lets do this permutation of a string question now 
        // it must be contiguous man yes ,yes,yes,yes
        unordered_map<char,int>mpp;
        for(int i=0;i<s1.length();i++)
        {
            mpp[s1[i]]++;
        }
        //frequency array has formed sucessfully  for string s1;
        //it is also a sliding window problem
        unordered_map<char,int>mpp1;
        int right=0;
        int left=0;
        deque<int>dq;
        while(right<s2.length())
        {
            dq.push_back(s2[right]);
            mpp1[s2[right]]++;
            if(dq.size()>s1.size())
            {
                char t=dq.front();
                mpp1[dq.front()]--;
                if(mpp1[t]<=0)
                {
                    mpp1.erase(t);
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
