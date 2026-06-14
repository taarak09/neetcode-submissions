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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next==nullptr && n==1)
        {
            return NULL;
        }
        ListNode * h=head;
        vector<ListNode *>temp;
        int count=0;
        while(h!=NULL)
        {
            temp.push_back(h);
            count++;
            h=h->next;
        }
        int k=(count-n)+1;
        if(k==1)
        {
            return head->next;
        }
        for(int i=0;i<temp.size();i++)
        {
           if(i==k-1 && i-1>=0 && i+1<temp.size())
           {
             temp[i-1]->next=temp[i+1];
             break;
           }
           else if (i==k-1 && i-1>=0 && !(i+1<temp.size()))
           {
            temp[i-1]->next=nullptr;
           
            break;
           }
        }
   return head; }
};
