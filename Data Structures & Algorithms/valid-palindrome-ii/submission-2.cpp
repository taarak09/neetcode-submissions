class Solution {
public:
    bool validPalindrome(string s) {
        //another easy peasy question it is man 
        string temp="";
        for(int i=0;i<s.length();i++)
        {
          if(isalnum(s[i]))
          {
            temp+=tolower(s[i]);
          }
        }
        int c1=0;
        return check (0,temp.size()-1,temp,c1);
        }
    bool check(int low,int high,string temp,int count)
    {
      if(count>1)
      {
        return false;
      }
        while(low<=high)
        {
          if(temp[low]==temp[high])
          {
             
             
          }
          else{
            int t1=count;
            t1++;
            int y=low;
            y++;
           bool one = check(y,high,temp,t1);
           int t2=count;
           t2++;
           int z=high;
           z--;
            bool two =check(low,z,temp,t2);
            if(one ||  two)
            {
              return true;
            }
            else{
              return false;
            }
          }
        
          low++;
          high--;
   }
   return true;
    }
};