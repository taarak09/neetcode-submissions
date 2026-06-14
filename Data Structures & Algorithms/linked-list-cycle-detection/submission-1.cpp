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
    bool hasCycle(ListNode* head) {
        if(head==NULL)
        {
            return false;
        }
       if(head->next==nullptr)
       {
        return false;
       }
        unordered_map<ListNode *,int>mpp;
        ListNode * h=head;
        while(h!=NULL)
        {
            if(mpp.find(h)!=mpp.end())
            {
                return true;
            }
            mpp[h]++;
            h=h->next;
        }
  return false;  }
};
