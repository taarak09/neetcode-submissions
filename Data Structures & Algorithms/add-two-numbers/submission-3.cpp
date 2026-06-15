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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        //numbers me convert karna is not possible here
        ListNode * h=l1;
        vector<ListNode*>temp;
        while(h!=NULL)
        {
            temp.push_back(h);
            h=h->next;
        }
        h=l2;
        vector<ListNode * > temp1;
        while(h!=NULL)
        {
            temp1.push_back(h);
            h=h->next;
        }
        int r=  max(temp.size(),temp1.size());
        int s= min(temp.size(),temp1.size());
        int big=0;
        if(r==temp.size())
        {
            
        }
        else{
            big=1;
        }
        vector<ListNode *>result;
        int carry=0;
        for(int i=0;i<r;i++)
        {
            int temp0;
            if(i<s)
            {
                temp0=temp[i]->val +temp1[i]->val+carry;
            }
            else{
                if(big==0)
                 temp0=temp[i]->val +carry;
                 if(big==1)
                 temp0=temp1[i]->val+carry;
            }
               int count=0;
               vector<int>k;
               if(temp0==0)
               {
                k.push_back(0);
                carry=0;
               }
               while(temp0!=0)
               {
                count++;
                k.push_back(temp0%10);
                temp0=temp0/10;

               }
               if(k.size()==1)
               {
                result.push_back(new ListNode(k[0]));
                carry=0;

               }
               else{
                result.push_back(new ListNode(k[0]));
                carry=k[1];

               }
            
        }
        if(carry!=0)
        {
            result.push_back(new ListNode(carry));
        }
       
        for(int i=0;i<result.size()-1;i++)
        {
            result[i]->next=result[i+1];

        }
  return result[0];  }
};
