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
        if(lists.empty())
        {
            return NULL;
        }
        if(lists.size()==1)
        {
            return lists[0];
        }
        vector<int>arr;
        vector<ListNode *>arr1;
        for(int i=0;i<lists.size();i++)
        {
            ListNode * h=lists[i];
            while(h!=NULL)
            {
                arr1.push_back(h);
                arr.push_back(h->val);
                h=h->next;
            }
        }
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr1.size()-1;i++)
        {
            arr1[i]->val=arr[i];
            arr1[i]->next=arr1[i+1];
            if(i==arr1.size()-2)
            {
                arr1[i+1]->val=arr[i+1];
                arr1[i+1]->next=nullptr;
            }

        }
  return arr1[0];  }
};
