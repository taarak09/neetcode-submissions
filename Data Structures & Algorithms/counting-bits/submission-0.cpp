class Solution {
public:
    vector<int> countBits(int n) {
        //new concept man 
        vector<int>result;
        for(int i=0;i<=n;i++)
        {
            bitset<32>bit(i);
            result.push_back(bit.count());
        }
   return result; }
};
