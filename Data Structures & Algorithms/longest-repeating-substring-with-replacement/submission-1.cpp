class Solution {
public:
    int characterReplacement(string s, int k) {
        //proper sliding windw problem
        int ans=INT_MIN;
        int left=0;
        int right=0;
        // this is th e game of only frequencies
        int arr[26]={0};
        int max_freq=0;

        while(right<s.length())
        {
            arr[s[right]-'A']++;
           max_freq=max(max_freq,arr[s[right]-'A']);
             while(((right-left)+1) -max_freq >k)
             {
                arr[s[left]-'A']--;
                left++;
             }






          ans=max(ans,(right-left)+1);
            right++;
        }
   return ans; }
};
