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
    void reorderList(ListNode* head) {
        if(head==NULL)
        {
            return ;
        }
        if(head->next==NULL)
        {
            return ;
        }
        ListNode * i=head;
        vector<int>temp;
       vector<ListNode*>t1;
        while(i!=NULL)
        {
            temp.push_back(i->val);
           t1.push_back(i);
            i=i->next;

        }
        int high=temp.size()-1;
        int low=0;
        vector<int>k;
        int count=1;
       while(low<=high)
       {
        if(count%2!=0)
        {
            k.push_back(temp[low]);
            low++;
        }
        else{
         k.push_back(temp[high]);
         high--;
        }
         count++;

       }
          
      for(int i=0;i<t1.size();i++)
      {
         t1[i]->val=k[i];
      }
     return ;  }
    ListNode * node(int y)
    {
        ListNode * o=new ListNode(y);
        return o;
    }
};
