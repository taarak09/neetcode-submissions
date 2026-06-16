/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<int>o;
        if(lists.empty())
        {
            return NULL;
        }
        if(lists.size()==1)
        {
            return lists[0];
        }
        vector<vector<int>>arr(lists.size());
        vector<ListNode *>arr1;
        for(int i=0;i<lists.size();i++)
        {
            ListNode * h=lists[i];
            while(h!=NULL)
            {
                arr1.push_back(h);
                arr[i].push_back(h->val);
                h=h->next;
            }
        }
        vector<int>final;
       if(arr.size()>=2)
       {vector<int>u;
        for(int i=0;i<arr[0].size();i++)
        {
            u.push_back(arr[0][i]);
        }
         for(int i=1;i<arr.size();i++)
         {
            
            if(i==1){
            vector<int>h;
            for(int j=0;j<arr[i].size();j++)
            {
                h.push_back(arr[i][j]);
            }
             o=merge(u,h);
            }else{
             vector<int>h;
            for(int j=0;j<arr[i].size();j++)
            {
                h.push_back(arr[i][j]);
            }
          o=merge(o,h);
            }
         }
       }
        for(int i=0;i<arr1.size()-1;i++)
        {
            arr1[i]->val=o[i];
            arr1[i]->next=arr1[i+1];
            if(i==arr1.size()-2)
            {
                arr1[i+1]->val=o[i+1];
                arr1[i+1]->next=nullptr;
            }

        }
  return arr1[0];  }



       vector<int> merge(vector<int>nums ,vector<int>arr)
       {
        vector<int>result;
         int left=0;
         int right=0;
         while(left<nums.size() && right<arr.size())
         {
            if(nums[left]>arr[right])
            {
                result.push_back(arr[right]);
                
                    right++;
                
            }
            else{
                result.push_back(nums[left]);
                left++;
            }
         }
         while(left<nums.size())
         {
            result.push_back(nums[left]);
            left++;
         }
         while(right<arr.size())
         {
            result.push_back(arr[right]);
            right++;
         }
      return result; }
  
};
