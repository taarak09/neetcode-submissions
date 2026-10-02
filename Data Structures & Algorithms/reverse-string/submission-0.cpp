class Solution {
public:
    void reverseString(vector<char>& s) {
        // easy question for the two pinters pattern 
        int low=0;
        int high = s.size()-1;
        while(low<high)
        {
             swap(s[low],s[high]);
             low++;
             high--;
        }
   return ; }
};