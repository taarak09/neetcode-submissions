class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // brute force approach dividing it into 3 segments
        // two conditions  overlapping or non -overlapping
        vector<vector<int>> result;
        if(intervals.empty())
        {
         result.push_back(newInterval);
         return result;
        }
        
        int index=-1;
        int index1=-1;
        for(int i=0;i<intervals.size();i++)
        {
            if(intervals[i][1]<newInterval[0])
            {
               result.push_back(intervals[i]);
            }
            else{
               if(newInterval[1]<intervals[i][0])
               {
                index=i;

               }
               else{
                index1=i;
               }
                  break;
               }
          
        }
          if(index!=-1)
            {
                result.push_back(newInterval);
                for(int i=index;i<intervals.size();i++)
                {
                   result.push_back(intervals[i]);
                }
                return result;

            }
            else if(index1!=-1){
                int temp=-1;
                int count=0;
                for(int i=index1;i<intervals.size();i++)
                {
                    if(newInterval[1]>=intervals[i][0])
                    {
                        count++;
                    }
                    else{
                        temp=i;
                        break;
                    }
                }
                count--;
                result.push_back({min(newInterval[0],intervals[index1][0]),max(newInterval[1],intervals[index1+count][1])});
                for(int i=temp;i<intervals.size();i++)
                {
                    result.push_back(intervals[i]);
                }

            }
            else if(index==-1 && index1==-1){
                result.push_back(newInterval);
                

            }


   return result; }
};
