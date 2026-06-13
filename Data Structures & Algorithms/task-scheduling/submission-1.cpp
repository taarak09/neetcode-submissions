class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mpp;
        for(char t: tasks)
        {
            mpp[t]++;
        }
        priority_queue<int>pq;
        for(auto const& [key,value]:mpp)
        {
            pq.push(value);
        }
        vector<int>remaining;
        int ans=0;
        int k=n+1;
        while(!pq.empty())
        {
            remaining.clear();
            int timeincycle=0;
         
            for(int i=0;i<k;i++)
            {
                if(!pq.empty()){
                timeincycle++;
                remaining.push_back(pq.top()-1);
                pq.pop();}
            }
            
            for(int it:remaining)
            {
                if(it>0)
                {
                    pq.push(it);
                }
            }
            if(pq.empty())
            {
             ans+=timeincycle;
            }
            else{
              ans+=k;
            }

        }
   return ans; }
};
