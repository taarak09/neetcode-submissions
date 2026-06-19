class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>bit(n);
        int low=0;
        int high=31;
        while(low<high)
        {
           uint32_t y=bit[low];
           bit[low]=bit[high];
           bit[high]=y;
            low++;
            high--;
        }
        long long ans=0;
        for(int i=0;i<32;i++)
        {
              double p =pow(2,i);
              ans+=p*bit[i];
        }
   return ans; }
};
