class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size()==1  && groupSize==1)
        {
            return true;
        }
         if(hand.size()==1  && groupSize!=1 )
         {
            return  false;
         }
        if(groupSize==1)
        {
            return true;
        }
        if(hand.size()%groupSize!=0)
        {
            return false;
        }
      map<int,int>mpp;
        for(int i=0;i<hand.size();i++)
        {
            mpp[hand[i]]++;
        }
        sort(hand.begin(),hand.end());
        vector<int>temp;
       
         for(int i=0;i<(hand.size()/groupSize);i++)
         {
            if(make_group(temp,groupSize,mpp))
            {

            }
            else{
                return false;
            }
         }


   return true; }
    bool make_group(vector<int>& temp,int groupSize,map<int,int>& mpp)
    {
       int count=0;
       int index=-1;
       temp.clear();
       for(auto const & [key,value]:mpp)
        {
            if(value>0){
            temp.push_back(key);}
        }
        if(temp.size()==1  && groupSize==1)
        {
            return true;
        }
         if(temp.size()==1  && groupSize!=1 )
         {
            return  false;
         }
        if(groupSize==1)
        {
            return true;
        }
       for(int i=0;i<temp.size()-1;i++)
       {
        
         if(mpp[temp[i]]>0)
         {
            if(temp[i]+1==temp[i+1]){
            count++;
            mpp[temp[i]]--;
            if(count==groupSize)
            {
                return true;
            }
            index=i;
            }
            else{
                count++;
                mpp[temp[i]]--;
                if(count==groupSize)
                {
                    return true;
                }
                else{
                    return false;
                }
            }

         }
       }
       if(index!=-1  && index==temp.size()-2)
       {
         count++;
                mpp[temp[index+1]]--;
                if(count==groupSize)
                {
                    return true;
                }
                else{
                    return false;
                }

       }










  return false;  }
};
