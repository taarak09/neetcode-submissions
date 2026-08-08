class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<string>st;
        for(int i=0;i<operations.size();i++)
        {
            if(operations[i]=="D" || operations[i]=="C" || operations[i]=="+")
            {
               if(operations[i]=="+")
               {
                  int a= stoi(st.top());
                  st.pop();
                  int b= stoi(st.top());
                  st.pop();
                  int c=a+b;
                  st.push(to_string(b));
                  st.push(to_string(a));
                  
                  st.push(to_string(c));
               }
               else if (operations[i]=="D")
               {
                int u=stoi(st.top());
               
                int c=2*u;
                st.push(to_string(c));

               }
               else{
                st.pop();
               }
            }
            else{
                st.push(operations[i]);
            }
        }
        int ans=0;
        while(!st.empty())
        {
           ans+= stoi(st.top());
           st.pop();
        }
   return ans; }
};