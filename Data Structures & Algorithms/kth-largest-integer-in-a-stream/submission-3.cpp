class KthLargest {
    //lets do priority queue questions my friend 
    // yes yes yes yes!!
public:
  // i need min heap here brother
  priority_queue<int,vector<int>,greater<int>>pq;
  int size=0;
    KthLargest(int k, vector<int>& nums) {
        size=k;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
            {
                pq.pop();
            }
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>size)
        {
            pq.pop();
        }
        return pq.top();
    }
};
