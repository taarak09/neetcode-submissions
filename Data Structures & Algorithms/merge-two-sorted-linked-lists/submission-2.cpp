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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * temp=list1;
        ListNode * temp1=list2;
        if(temp==NULL  && temp1==NULL)
        {
            return NULL;
        }
        if(temp==NULL)
        {
            return temp1;
        }
        if(temp1==NULL)
        {
            return temp;
        }
        multiset<int>ms;
        vector<ListNode*>arr;
        while(temp!=NULL)
        {
           ms.insert(temp->val);
           arr.push_back(temp);
           temp=temp->next;
        }
        
        while(temp1!=NULL)
        {
            ms.insert(temp1->val);
              arr.push_back(temp1);
            temp1=temp1->next;
          
        }
    int count=0;
        for(int r: ms)
        {
            if(count>0)
            {
                arr[count-1]->next=arr[count];
            }
            arr[count]->val=r;
            if(count==arr.size()-1)
            {
                arr[count]->next=nullptr;
            }
            count++;
        }
                     
   return arr[0]; }
};
