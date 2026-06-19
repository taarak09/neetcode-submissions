class Solution {
public:
    int hammingWeight(uint32_t n) {
      bitset<32>taa(n);
      int ans=0;
      for(int i=0;i<32;i++)
      {
        if(taa[i]==1)
      {
        ans++;
      }
      }

   return ans; }
};
