class Solution {
public:
    bool isPalindrome(string s) {
        // another easy peasy question it is 
       string temp="";
       for(int i=0;i<s.length();i++)
       {
         if(isalnum(s[i]))
         {
            temp+=tolower(s[i]);
         }
         
       }
       int low=0;
       int high=temp.size()-1;
       while(low<high)
       {
         if ( temp[low]==temp[high])
         {

         }
         else{
            return false;
         }
         low++;
         high--;
       }
    return true;}
};
