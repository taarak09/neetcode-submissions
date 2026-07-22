class matrix{
public:
double posi;
double spee;
double time ;
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
            //har ek car ke sath uska associated time nikalo boss
            time.push_back((target-arr[i].first)/arr[i].second);

        }
        stack<matrix>st;
        for(int i=0;i<arr.size();i++)
        {
            st.push({arr[i].first,arr[i].second,time[i]});
        }
        int count=0;
        //these are actually my number of fleets which i am going to count nowadays 
        while(!st.empty())
        {
            double t1=st.top().posi;
            double t2= st.top().spee;
            double t3=st.top().time;
            st.pop();
            while(!st.empty())
            {
                double t4=st.top().posi;
                double t5= st.top().spee;
                double t6=st.top().time;
                if(t6<=t3)
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
