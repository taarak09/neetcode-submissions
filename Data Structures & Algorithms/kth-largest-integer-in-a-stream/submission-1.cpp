class KthLargest {
public:
int target;
priority_queue<int>pq;
    KthLargest(int k, vector<int>& nums) {
        target=k;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        
    }
    
    int add(int val) {
        pq.push(val);
        vector<int>temp;
        int ans=0;
        for(int i=0;i<target;i++)
        {
              temp.push_back(pq.top());
              pq.pop();
        }
       for(int u:temp)
       {
        pq.push(u);
       }
       return temp[temp.size()-1];
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */