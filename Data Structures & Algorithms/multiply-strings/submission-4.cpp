class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" ||  num2=="0")
        {
            return "0";
        }
        // the most optimal and aalso the most important algirithm
        //magic algorithm
        int n=num1.size();
        int m=num2.size();
        vector<int>ans;
        ans.resize(m+n);
        fill(ans.begin(),ans.end(),0);
        //automatic carry adjustment as well;
        //actually a very beautiful algorithm it is 
        for(int i=num1.size()-1;i>=0 ;i--)
        {
            for(int j=num2.size()-1;j>=0;j--)
            {
               int mul= (num2[j]-'0')*(num1[i]-'0');
               int p1=i+j+1;// digit goes here
               int p2=i+j;//carry goes here
               int sum=mul+ans[p1];
               ans[p1]=sum%10;
               ans[p2]+=sum/10;
            }
        }

        string result="";
        for(int i=0;i<ans.size();i++)
        {
            
            result+=(to_string(ans[i]));
        }
        int index=0;
        int count=0;
         while(result[index]=='0')
         {
            count++;
            index++;
         }
         string h1="";
         for(int i=count;i<result.size();i++)
         {
             h1+=result[i];
         }
    return h1;}
};
