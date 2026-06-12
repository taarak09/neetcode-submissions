class KthLargest {
public:
  
   vector<int>temp;
   int target;
    KthLargest(int k, vector<int>& nums) {
        temp=nums;
        target=k;
    }
    
    int add(int val) {
       
        temp.push_back(val);
        sort(temp.begin(),temp.end());
        reverse(temp.begin(),temp.end());
       return temp[target-1];
       

    }
};
