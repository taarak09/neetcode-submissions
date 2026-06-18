class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        vector<int>temp;
        int breakaway=-1;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]<=nums[i-1])
            {
                 temp.push_back(nums[i]);
            }
            else{
                 breakaway=i-1;
                 temp.push_back(nums[i]);
                 
                 break;
            }
        }
        if(breakaway==-1)
        {
            sort(nums.begin(),nums.end());
            return ;
        }
        //now i got a valid breakaway point
        //longest prefix is actually fixed now
        vector<int>temp1;
        for(int i=0;i<breakaway;i++)
        {
            temp1.push_back(nums[i]);
        }
        reverse(temp.begin(),temp.end());
        
        for(int i=temp.size()-1;i>=0;i--)
        {
            if(nums[breakaway]>=temp[i])
            {

            }
            else{
               
               temp1.push_back(temp[i]);
               temp[i]=nums[breakaway];
                break;
            }
        }
        sort(temp.begin(),temp.end());
        for(int y:temp)
        {
            temp1.push_back(y);
        }
        nums.clear();
        nums=temp1;
        


  return ;  }
};