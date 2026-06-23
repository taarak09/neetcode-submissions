class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int count=0;
        long long num=0;
        reverse(digits.begin(),digits.end());
        for(int i=0;i<digits.size();i++)
        {
             double p= pow(10,count);
             num+=(p*digits[i]);
             count++;
        }
        num++;
        vector<int>result;
        while(num!=0)
        {
            result.push_back(num%10);
            num/=10;
        }
        reverse(result.begin(),result.end());
  return result;  }
};
