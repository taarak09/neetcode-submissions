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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL)
        {
            return head;
        }
        if(head->next==nullptr)
        {
            return head;
        }
        ListNode * temp=head;
        vector<int>t1;
        while(temp!=NULL)
        {
             t1.push_back(temp->val);
             temp=temp->next;
        }
        reverse(t1.begin(),t1.end());
        temp=head;
       for(int i=0;i<t1.size();i++)
       {
         temp->val=t1[i];
         temp=temp->next;
       }
   return head; }
};
