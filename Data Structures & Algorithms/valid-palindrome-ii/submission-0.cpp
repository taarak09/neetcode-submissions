class Solution {
public:
    bool validPalindrome(string s) {
        int left=0;
        int right=s.length()-1;
       int  count=0;
       int flag1=0;
       int flag2=0;
        while(left<=right)
        {
          if(s[left]==s[right])
          {
            left++;
            right--;
          }
          else{
            if(count==1)
            {
               flag1=1;
               break;
            }
            left++;
            count++;
          }
        }
        count=0;
        left=0;
        right=s.length()-1;
          while(left<=right)
        {
          if(s[left]==s[right])
          {
            left++;
            right--;
          }
          else{
            if(count==1)
            {
               flag2=1;
               break;
            }
           right--;
            count++;
          }
        }
        if(flag1==0 || flag2==0)
        {
            return true;
        }
      
      
      return false;  }
};