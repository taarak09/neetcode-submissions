class matrix{
public:
double a;
double b;
 double c;
};
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<double,double>>arr;
        for(int i=0;i<position.size();i++)
        {
            arr.push_back({position[i],speed[i]});

        }
        sort(arr.begin(),arr.end());
       
        vector<double>time;
      
        for(int i=0;i<arr.size();i++)
        {
            time.push_back((target-arr[i].first)/arr[i].second);
        }
       //thats why stack is used here
       stack<matrix>st;
      for(int i=0;i<arr.size();i++)
      {
        st.push({arr[i].first,arr[i].second,time[i]});
      }
      int count=0;
      while(!st.empty())
      {
        double d=st.top().a;
        double e=st.top().b;
        double f= st.top().c;
        st.pop();
        while(!st.empty())
        {
              double d1=st.top().a;
              double e1=st.top().b;
              double f1= st.top().c;
              if(f>=f1)
              {
                st.pop();
              }
              else{
                break;
              }
        }
        count++;
      }

       return count;}
};
