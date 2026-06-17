//important concept of isalnum() okay my boy yes,yes,yes,yes
class Solution {
public:
    bool isPalindrome(string s) {
        string t="";
        for(int i=0;i<s.length();i++)
        {
            if(isalnum(s[i])){
          t+=tolower(s[i]);}
        }
        int low=0;
        int high=t.length()-1;
        while(low<=high)
        {
           
            if(t[low]==t[high])
            {
                low++;
                high--;
            }
            else{
                return false;
            }
        }
  return true;  }
};
