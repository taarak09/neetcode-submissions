class Solution {
public:

    vector<vector<int>> merge(vector<vector<int>>& intervals)
    {
        if(intervals.size()==1)
        {
            return intervals;
        }
        vector<vector<int>>j1;
       j1=intervals;
       vector<pair<int,int>>j2;
       for(int i=0;i<j1.size();i++)
       {
        j2.push_back({j1[i][0],j1[i][1]});
        
       }
    sort(j2.begin(),j2.end());
     vector<vector<int>>j;
     for(int i=0;i<j2.size();i++)
     {
        j.push_back({j2[i].first,j2[i].second});
     }

         for(int i=0;i<j.size()-1;i++)
        {
            if(j[i][1]<j[i+1][0])
            {
                
            }
            else{
               j=merge1(j);
               i=-1;
            }
        }
    return j;}
    vector<vector<int>> merge1(vector<vector<int>>& intervals) {
        vector<vector<int>>result;
        int index=-1;
        for(int i=0;i<intervals.size()-1;i++)
        {
            if(intervals[i][1]<intervals[i+1][0])
            {
                result.push_back(intervals[i]);
            }
            else{
                index=i;
                break;
            }
        }
        if(index==-1)
        {
            return result;
        }
       //overlapping phase has started 
       int index1=-1;
       int count=0;
       for(int i=index;i<intervals.size()-1;i++)
       {
         if(intervals[i][1]>=intervals[i+1][0])
         {
            count++;
         }
         else{
            break;
         }
       }
      int y=index+count;
      vector<int>temp;
      for(int i=index;i<=y;i++)
      {
          temp.push_back(intervals[i][0]);
          temp.push_back(intervals[i][1]);
      }
      sort(temp.begin(),temp.end());
       result.push_back({temp[0],temp[temp.size()-1]});
       for(int i=index+count+1;i<intervals.size();i++)
       {
        result.push_back(intervals[i]);
       }
    return result;}

};
