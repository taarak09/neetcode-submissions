
class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode * i=head;
        int count=0;
        vector<ListNode *>temp;
        while(i!=NULL)
        {
           count++;
           temp.push_back(i);
           i=i->next;
        }
      
        vector<ListNode*>arr;
        vector<ListNode *>result;
      
        for(int i=0;i<temp.size();i++)
        {
             arr.push_back(temp[i]);
            if((i+1)%k==0)
            {
               reverse(arr.begin(),arr.end());
               for(ListNode * u:arr)
               {
                result.push_back(u);
               }
               arr.clear();
               

            }
           


        }
       if(arr.size()==k)
       {
        reverse(arr.begin(),arr.end());
               for(ListNode * u:arr)
               {
                result.push_back(u);
               }
               arr.clear();
              
       }
       else{
         for(ListNode * u:arr)
         {
            result.push_back(u);
         }
         arr.clear();
       }
       for(int i=0;i<result.size()-1;i++)
       {
         result[i]->next=result[i+1];
         if(i==result.size()-2)
         {
            result[i+1]->next=nullptr;
         }
       }
       
  return  result[0];}
};
