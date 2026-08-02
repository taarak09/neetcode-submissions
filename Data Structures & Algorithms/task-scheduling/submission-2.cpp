class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        //lets do this task scheduler 
        unordered_map<char,int>mpp;
        for(int i=0;i<tasks.size();i++)
        {
            mpp[tasks[i]]++;
        }
        priority_queue<int>pq;
        for(auto const& [key,value]:mpp)
        {
            pq.push(value);
        }
        //task with most frequent must be executed first my friend yes ! yes! yes! yes !
        vector<int>remaining;
        int k=n+1;
        int ans=0;
        while(!pq.empty())
        {
            remaining.clear();
            int timecycles=0;
            for(int i=0;i<k;i++)
            {
                if(!pq.empty())
                {
                    timecycles++;
                    remaining.push_back(pq.top()-1);
                    pq.pop();
                }
            }
            for(int it: remaining)
            {
                if(it>0)
                {
                    pq.push(it);
                }

            }
            if(pq.empty())
            {
                ans+=timecycles;
            }
            else{
                ans+=k;
            }

        }
       
   return ans; }
};
