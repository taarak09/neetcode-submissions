class Solution {
public:
    bool isPalindrome(string s) {
        //  two pointer approach will be used here 
        string temp="";
        for(int i=0;i<s.length();i++)
        {
            if(isalnum(s[i]))
            {
                temp+=tolower(s[i]);
            }
        }
        int right=temp.length()-1;
        int left=0;
        while(left<=right)
        {
            if(temp[left]==temp[right])
            {

            }
            else{
                return false;
            }
            left++;
            right--;
        }
    return true;}
};
