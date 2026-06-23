class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        //because of long lng overflow;
        reverse(digits.begin(),digits.end());
        digits[0]+=1;
        if(digits[0]<10)
        {
            reverse(digits.begin(),digits.end());
            return  digits;
        }
        else{
            digits[0]=0;
            int carry=1;

            for(int i=1;i<digits.size();i++)
            {
               digits[i]+=carry;
               if(digits[i]<10)
               {
                   reverse(digits.begin(),digits.end());
                   return  digits;
               }
               else{
                digits[i]=0;
               }
            }
           digits.push_back(1);
           reverse(digits.begin(),digits.end());

        }
  return digits;  }
};
