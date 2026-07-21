class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int>result(temperatures.size());
        // this question is same as the next greater element question 
        stack<pair<int,int>>st;
        for(int i=temperatures.size()-1;i>=0;i--)
        {
          if(st.empty())
          {
            result[i]=0;
            st.push({temperatures[i],i});
          }
          else{
            if(st.top().first>temperatures[i])
            {
              result[i]=(st.top().second-i);
              st.push({temperatures[i],i});
            }
            else{
              while(!st.empty()  && temperatures[i]>=st.top().first)
              {
                st.pop();
              }
              if(st.empty())
              {
                result[i]=0;
                st.push({temperatures[i],i});
              }
              else{
                result[i]=st.top().second-i;
                st.push({temperatures[i],i});
              }
            }
          }





        }

   return result; }
};
